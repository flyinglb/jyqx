//���ڴ���

inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name("���ڴ���", "bowl");
        set_weight(50);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "ֻ");
                set("long", "����һֻ��ʢˮ�Ĵִɴ��롣\n");
		set("value", 0);
		set("max_liquid", 6);
        }

    // because a container can contain different liquid
    // we set it to contain tea at the beginning
    set("liquid", ([
	"type": "water",
	"name": "��ˮ",
	"remaining": 0,
	"drunk_apply": 0,
    ]));
}
