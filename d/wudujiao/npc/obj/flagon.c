// flagon.c  �ƺ�

 inherit ITEM;
inherit F_LIQUID;
// inherit COMBINED_ITEM;

void create()
{
	set_name("�ƺ�", ({"jiu hu", "hu", "flagon"}));
	set_weight(700);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ������װ�վƵĴ�ƺ���\n");
		set("unit", "��");
		set("value", 100);
		set("max_liquid", 15);
	}
 
	// because a container can contain different liquid
	// we set it to contain wine at the beginning
	set("liquid", ([
		"type": "alcohol",
		"name": "�վ�",
		"remaining": 15,
		"drunk_apply": 3,
              "slumber_effect": 100,
	]));
}
