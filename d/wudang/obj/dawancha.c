// dawancha.c �ִŴ���
// By Marz 03/29/96

inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name("�ִŴ���", ({"wan", "da wan","ci wan"}));
	set_weight(50);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ�����ߴִŴ��롣\n");
		set("unit", "��");
		set("value", 0);
        set("max_liquid", 4);
    }

    // because a container can contain different liquid
    // we set it to contain tea at the beginning
    set("liquid", ([
        "type": "tea",
        "name": "��ˮ",
        "remaining": 4,
        "drunk_supply": 0,
    ]));
}
