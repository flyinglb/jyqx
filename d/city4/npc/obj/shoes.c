/*  <SecCrypt CPL V3R05>  */
 
//  shoes.c

#include  <armor.h>
#include  <ansi.h>

inherit  BOOTS;


void  create()
{
	set_name(YEL  "�廨СЬ"  NOR,  ({  "shoes"  })  );
	set_weight(900);
	if(  clonep()  )
		set_default_object(__FILE__);
	else  {
                                set("long",  "һ˫С�ɾ��µ��廨Ь��    \n");
		set("material",  "cloth");
		set("unit",  "˫");
//		set("value",  300);
		set("armor_prop/armor",  1  );
		set("female_only",  1);
	}
	setup();
}
//int  query_autoload()  {  return  1;  }

