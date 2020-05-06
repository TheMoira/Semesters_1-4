#include <wx/dc.h>
#include <memory>

#include "ChartClass.h"

#include "vecmat.h"

Matrix transform;

ChartClass::ChartClass(std::shared_ptr<ConfigClass> c)
{
	cfg = std::move(c);
	x_step = 200;
}

void ChartClass::Set_Range()
{
	double xmin = 9999.9, xmax = -9999.9, ymin = 9999.9, ymax = -9999.9;
	double x, y, step;
	int i;

	xmin = cfg->Get_x_start();
	xmax = cfg->Get_x_stop();

	step = (cfg->Get_x_stop() - cfg->Get_x_start()) / (double)x_step;
	x = cfg->Get_x_start();

	for (i = 0;i <= x_step;i++)
	{
		y = GetFunctionValue(x);
		if (y > ymax) ymax = y;
		if (y < ymin) ymin = y;
		x = x + step;
	}

	y_min = ymin;
	y_max = ymax;
	x_min = xmin;
	x_max = xmax;
}


double ChartClass::GetFunctionValue(double x)
{
	if (cfg->Get_F_type() == 1) return x * x;
	if (cfg->Get_F_type() == 2) return 0.5*exp(4 * x - 3 * x*x);
	return x + sin(x*4.0);
}

void ChartClass::Draw(wxDC *dc, int w, int h)
{
	dc->SetBackground(wxBrush(RGB(255, 255, 255)));
	dc->Clear();
	dc->SetPen(wxPen(RGB(255, 0, 0)));
	dc->DrawRectangle(10, 10, w - 20, h - 20);

	dc->SetClippingRegion(10, 10, w - 20, h - 20);
	dc->SetPen(wxPen(RGB(0, 0, 0)));

	Transformation(w,h);

	double xstart = cfg->Get_x_start();
	double xstop = cfg->Get_x_stop();

	line2d(xstart, 0, xstop, 0, w, h, dc);
	line2d(0, Get_Y_min(), 0, Get_Y_max(), w, h, dc);

	double tempX = x_min;
	double tempY = y_min;

	double x = 1 + (int)((cfg->Get_x1() - cfg->Get_x0()) / 10);
	double y = 1 + (int)((cfg->Get_y1() - cfg->Get_y0()) / 10);

	while(tempX <= x_max)
	{
		drawValues(dc, wxString::Format(wxT("%.2g"), tempX), tempX, 0, w, h);
		tempX += x/2;
	}
	while (tempY <= y_max)
	{
		drawValues(dc, wxString::Format(wxT("%.2g"), tempY), 0, tempY, w, h);
		tempY += y / 2;
	}

	double step = (cfg->Get_x_stop() - cfg->Get_x_start()) / (double)x_step;

	x = x_min + step;
	y = GetFunctionValue(x);
	double y2;


	dc->SetPen(wxPen(RGB(255,0,255)));

	Transformation(w,h);

	for (int i = 0; i <= x_step; i++)
	{
		x = x + step;
		y2 = GetFunctionValue(x);
		line2d(x - step, y, x, y2, w, h, dc);
		y = y2;

	}

	dc->SetPen(wxPen(RGB(0, 0, 0)));
	line2d(x_min, 0, x_max, 0, w, h, dc);
	line2d(0, y_min, 0, y_max, w, h, dc);



	//dc->DrawDuck();
}

void ChartClass::drawValues(wxDC *dc,wxString text, double x, double y, int w, int h) 
{
	Vector vec;
	vec.Set(x, y);
	vec = transform * vec;
	dc->DrawRotatedText(text, vec.GetX(), h - vec.GetY(), - cfg->Get_Alpha());
}

void ChartClass::Transformation(int w, int h)
{
	transform = (Set_Rotate(w, h) * Set_Translation(cfg->Get_dX(), cfg->Get_dY()) * Set_Scale(w, h));
}

void ChartClass::line2d(double x1, double y1, double x2, double y2, int w, int h, wxDC *dc)
{
	Vector vec1, vec2;
	vec1.Set(x1, y1);
	vec2.Set(x2, y2);

	vec1 = transform * vec1;
	vec2 = transform * vec2;

	dc->DrawLine(vec1.GetX(), h - vec1.GetY(), vec2.GetX(), h - vec2.GetY());
}

double ChartClass::Get_Y_min()
{
	Set_Range();
	return y_min;
}

double ChartClass::Get_Y_max()
{
	Set_Range();
	return y_max;
}


Matrix ChartClass::Set_Rotate(int w, int h)
{
	Matrix transformation;

	int x, y;

	if (cfg->RotateScreenCenter())
	{
		x = (w - 20) / 2;
		y = (h - 20) / 2;
	}
	else
	{
		Vector vec;
		vec.Set(0, 0);
		vec = Set_Translation(cfg->Get_dX(), cfg->Get_dY()) * Set_Scale(w, h) * vec;
		x = vec.GetX();
		y = vec.GetY();
	}

	double cos1 = cos(cfg->Get_Alpha() * M_PI / 180.0);
	double sin1 = sin(cfg->Get_Alpha() * M_PI / 180.0);

	transformation.data[0][0] = transformation.data[1][1] = cos1;
	transformation.data[0][1] = sin1;
	transformation.data[1][0] = -sin1;
	transformation.data[0][2] = x * (1 - cos1) + y * (-sin1);
	transformation.data[1][2] = -x * (-sin1) + y * (1 - cos1);

	return transformation;

}

Matrix ChartClass::Set_Scale(int x, int y)
{
	Matrix transformation;

//	transformation.data[0][0] = x;
	//transformation.data[1][1] = y;

	transformation.data[0][0] = (x - 20.0) / (cfg->Get_x1() - cfg->Get_x0());
	transformation.data[1][1] = (y - 20.0) / (cfg->Get_y1() - cfg->Get_y0());
	transformation.data[0][2] = -10.0 - transformation.data[0][0] * cfg->Get_x0();
	transformation.data[1][2] = 10.0 - transformation.data[1][1] * cfg->Get_y0();

	return transformation;
}



Matrix ChartClass::Set_Translation(double x, double y)
{
	Matrix transformation;

	transformation.data[0][2] = x;
	transformation.data[1][2] = y;
	transformation.data[1][1] = 1.0;
	transformation.data[0][0] = 1.0;

	return transformation;
}


