/*  <SecCrypt CPL V3R05>  */
 
//  magua.c

#include  <armor.h>

inherit  CLOTH;

void  create()
{
                set_name("���",  ({  "magua"}));
                set_weight(3000);
                if(  clonep()  )
                                set_default_object(__FILE__);
                else  {
		set("long",  "һ������ɫ����ӣ�\n");
                                set("unit",  "��");
                                set("value",  500);
                                set("material",  "cloth");
                                set("armor_prop/armor",  5);
                }
                setup();
}

