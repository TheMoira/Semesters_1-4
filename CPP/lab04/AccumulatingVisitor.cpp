#include "AccumulatingVisitor.h"



/* void AccumulatingVisitor::visit( Data* d)
{
    if(empty)
    {
        md << d->get();
        empty = false;
    }
    else
    {
        md << (md->get() + d->get());
    }
} */

void AccumulatingVisitor::visit( IntData* d)
{
        if(empty)
    {
        md = d->get();
        empty = false;
    }
    else
    {
        md += d->get();
    }
}


void AccumulatingVisitor::visit (FloatData* d)
{
    if(empty)
    {
        md = d->getFloat();
        empty = false;
    }
    else
    {
        md += d->getFloat();
    }
}