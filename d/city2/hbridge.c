
inherit ROOM;
int do_out(string arg);

void create()
{
        set("short", "С��");
        set("long",
        "����һ���ƾɵ�ʯ�ţ������ǻ��Ǻӻ�������ˮ��ˮ����ȥ���壬\n"+
	"�����ǽ��ʹ����ŵıؾ�֮·��\n");
        set("outdoors", "city2");
        set("exits", ([
                "north" : __DIR__"di_anmen",
        ]));
	set("no_clean_up", 0);
        setup();
	replace_program(ROOM);
}


