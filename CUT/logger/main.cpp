#include<stdio.h>
#include"emp_details.h"
#include"logger.h"

int main()
{
printf("Info:Date %s Time %s file %s func %s line %d\n",__DATE__,__TIME__,__FILE__,__func__,__LINE__);

LOG_INFO("Details are ");
Employee e1();
e1.accept();
e1.display();

return 0;
}

