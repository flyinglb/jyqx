//����bearheart
//by steel
#include "ansi.h"

inherit ITEM;

void create()
{
    set_name("����",({"bearheart"}));
    set_weight(10);
    if( clonep() )
		set_default_object(__FILE__);
    else
  {
    set("unit","��");
    set("long","����һ�����ʵ�����,���滹����Ѫ˿.\n");
    set("value","1000");
    set("material","fesh"); 
  }    
 setup();
}

