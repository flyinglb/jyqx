/*  <SecCrypt CPL V3R05>  */
 
//  pink_cloth.c

#include  <armor.h>
#include  <ansi.h>

inherit  CLOTH;

void  create()
{
	set_name(HIG  "��ɴ��ȹ"  NOR,  ({  "skirt",  "cloth"  })  );
	set_weight(1000);
	if(  clonep()  )
		set_default_object(__FILE__);
	else  {
		set("long",  "һ���������ʵ�ɴȹ������������һ�ɵ��㡣\n");
		set("unit",  "��");
		set("value",  0);
		set("material",  "cloth");
		set("armor_prop/armor",  1);
		set("armor_prop/personality",  3);
		set("female_only",  1);
	}
	setup();
}

//int  query_autoload()  {  return  1;  }

