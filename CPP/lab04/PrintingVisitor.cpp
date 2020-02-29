#include "PrintingVisitor.h"
#include <iostream>




/* void PrintingVisitor::visit( Data* d)
{
    md << d->get();

    std::cout<< md->get() <<" ";

} */

void PrintingVisitor::visit( IntData* d)
{
    std::cout<< d -> get() <<" ";
}
void PrintingVisitor::visit (FloatData* d)
{
    std::cout<< d -> getFloat() <<" ";
}