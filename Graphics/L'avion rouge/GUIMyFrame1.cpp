#include "GUIMyFrame1.h"
#include <vector>
#include <fstream>
//#include "vecmat.h"

struct Point {
	float x, y, z;
	Point(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}
};

struct Color {
	int R, G, B;
	Color(int _R, int _G, int _B) : R(_R), G(_G), B(_B) {}
};

struct Segment {
	Point begin, end;
	Color color;
	Segment(Point _begin, Point _end, Color _color) : begin(_begin), end(_end), color(_color) {}
};

std::vector<Segment> data;

GUIMyFrame1::GUIMyFrame1(wxWindow* parent)
	:
	MyFrame1(parent)
{
	m_button_load_geometry->SetLabel(_("Wczytaj Geometri\u0119"));
	m_staticText25->SetLabel(_("Obr\u00F3t X:"));
	m_staticText27->SetLabel(_("Obr\u00F3t Y:"));
	m_staticText29->SetLabel(_("Obr\u00F3t Z:"));

	WxSB_TranslationX->SetRange(0, 200); WxSB_TranslationX->SetValue(100);
	WxSB_TranslationY->SetRange(0, 200); WxSB_TranslationY->SetValue(100);
	WxSB_TranslationZ->SetRange(0, 200); WxSB_TranslationZ->SetValue(100);

	WxSB_RotateX->SetRange(0, 360); WxSB_RotateX->SetValue(0);
	WxSB_RotateY->SetRange(0, 360); WxSB_RotateY->SetValue(0);
	WxSB_RotateZ->SetRange(0, 360); WxSB_RotateZ->SetValue(0);

	WxSB_ScaleX->SetRange(1, 200); WxSB_ScaleX->SetValue(100);
	WxSB_ScaleY->SetRange(1, 200); WxSB_ScaleY->SetValue(100);
	WxSB_ScaleZ->SetRange(1, 200); WxSB_ScaleZ->SetValue(100);
}

void GUIMyFrame1::WxPanel_Repaint(wxUpdateUIEvent& event)
{
	Repaint();
}

void GUIMyFrame1::m_button_load_geometry_click(wxCommandEvent& event)
{
	wxFileDialog WxOpenFileDialog(this, wxT("Choose a file"), wxT(""), wxT(""), wxT("Geometry file (*.geo)|*.geo"), wxFD_OPEN | wxFD_FILE_MUST_EXIST);

	if (WxOpenFileDialog.ShowModal() == wxID_OK)
	{
		double x1, y1, z1, x2, y2, z2;
		int r, g, b;

		std::ifstream in(WxOpenFileDialog.GetPath().ToAscii());
		if (in.is_open())
		{
			data.clear();
			while (!in.eof())
			{
				in >> x1 >> y1 >> z1 >> x2 >> y2 >> z2 >> r >> g >> b;
				data.push_back(Segment(Point(x1, y1, z1), Point(x2, y2, z2), Color(r, g, b)));
			}
			in.close();
		}
	}
}

void GUIMyFrame1::Scrolls_Updated(wxScrollEvent& event)
{
	WxST_TranslationX->SetLabel(wxString::Format(wxT("%g"), (WxSB_TranslationX->GetValue() - 10) / 10.0));
	WxST_TranslationY->SetLabel(wxString::Format(wxT("%g"), (WxSB_TranslationY->GetValue() - 10) / 10.0));
	WxST_TranslationZ->SetLabel(wxString::Format(wxT("%g"), (WxSB_TranslationZ->GetValue() - 10) / 10.0));

	WxST_RotateX->SetLabel(wxString::Format(wxT("%d"), WxSB_RotateX->GetValue()));
	WxST_RotateY->SetLabel(wxString::Format(wxT("%d"), WxSB_RotateY->GetValue()));
	WxST_RotateZ->SetLabel(wxString::Format(wxT("%d"), WxSB_RotateZ->GetValue()));

	WxST_ScaleX->SetLabel(wxString::Format(wxT("%g"), WxSB_ScaleX->GetValue() / 20.0));
	WxST_ScaleY->SetLabel(wxString::Format(wxT("%g"), WxSB_ScaleY->GetValue() / 20.0));
	WxST_ScaleZ->SetLabel(wxString::Format(wxT("%g"), WxSB_ScaleZ->GetValue() / 20.0));


	Repaint();
}


Matrix4 GUIMyFrame1::Translation(double x, double y, double z)
{
	Matrix4 transformation;

	transformation.data[0][0] = transformation.data[1][1] = transformation.data[2][2] = 1.0;
	transformation.data[0][3] = x;
	transformation.data[1][3] = -y;
	transformation.data[2][3] = z;
	
	return transformation;
}

Matrix4 GUIMyFrame1::Scale(double x, double y, double z)
{
	Matrix4 transformation;
	transformation.data[0][0] = x;
	transformation.data[1][1] = -y;
	transformation.data[2][2] = z;
	return transformation;
}

Matrix4 GUIMyFrame1::RotationX(double angle)
{
	double cosx = cos(angle / 180 * M_PI);
	double sinx = sin(angle / 180 * M_PI);

	Matrix4 transformation;
	transformation.data[0][0] = 1.0;
	transformation.data[1][1] = transformation.data[2][2] = cosx;
	transformation.data[1][2] = sinx;
	transformation.data[2][1] = -sinx;

	return transformation;

}


Matrix4 GUIMyFrame1::RotationY(double angle)
{
	double cosx = cos(angle / 180 * M_PI);
	double sinx = sin(angle / 180 * M_PI);

	Matrix4 transformation;
	transformation.data[1][1] = 1.0;
	transformation.data[0][0] = transformation.data[2][2] = cosx;
	transformation.data[0][2] = sinx;
	transformation.data[2][0] = -sinx;

	return transformation;
}

Matrix4 GUIMyFrame1::RotationZ(double angle)
{
	double cosx = cos(angle / 180 * M_PI);
	double sinx = sin(angle / 180 * M_PI);

	Matrix4 transformation;
	transformation.data[2][2] = 1.0;
	transformation.data[1][1] = transformation.data[0][0] = cosx;
	transformation.data[1][0] = -sinx;
	transformation.data[0][1] = sinx;

	return transformation;
}


void GUIMyFrame1::transformation()
{
	//Matrix4 temp = RotationX(WxSB_RotateX->GetValue()) * RotationY(WxSB_RotateY->GetValue()) *  RotationZ(WxSB_RotateZ->GetValue());

	transform = Translation(WxSB_TranslationX->GetValue(), WxSB_TranslationY->GetValue(), WxSB_TranslationZ->GetValue()) 
		* RotationX(WxSB_RotateX->GetValue()) * RotationY(WxSB_RotateY->GetValue()) *  RotationZ(WxSB_RotateZ->GetValue()) * Scale(WxSB_ScaleX->GetValue(), WxSB_ScaleY->GetValue(), WxSB_ScaleZ->GetValue());
}

void GUIMyFrame1::Repaint()
{
	wxClientDC dc(WxPanel);
	wxBufferedDC dcBuff(&dc);

	int width, height;
	WxPanel->GetSize(&width, &height);
	dcBuff.SetBackground(wxBrush(RGB(255, 255, 255)));
	dcBuff.Clear();

	transformation();
	Matrix4 center;
	center.data[0][0] = center.data[1][1] = center.data[2][2] = 1;
	center.data[0][3] = center.data[1][3] = 0.5;

	for (int i = 0; i < data.size(); i++) {

		Vector4 vec1;
		vec1.Set(data[i].begin.x, data[i].begin.y, data[i].begin.z);

		Vector4 vec2;
		vec2.Set(data[i].end.x, data[i].end.y, data[i].end.z);

		//vec1 = translation( * vec1;
		//vec2 = transform * vec2;

		vec1 = transform * vec1;
		vec2 = transform * vec2;

		//ustawianie skali w zaleznosci od odleglosci od ekranu
		vec1.Set(vec1.GetX() / vec1.GetZ(), vec1.GetY() / vec1.GetZ(), vec1.GetZ());
		vec2.Set(vec2.GetX() / vec2.GetZ(), vec2.GetY() / vec2.GetZ(), vec2.GetZ());

		//ustawianie na srodku
		vec1 = center * vec1;
		vec2 = center * vec2;


		dcBuff.SetPen(wxPen(RGB(data[i].color.R, data[i].color.G, data[i].color.B)));
		//dcBuff.DrawLine(vec1.GetX() * width/2, vec1.GetY() * height/2, vec2.GetX() * width/2, vec2.GetY() * height/2);
		dcBuff.DrawLine(vec1.GetX() * width, vec1.GetY() * height, vec2.GetX() * width, vec2.GetY() * height);

	}

}