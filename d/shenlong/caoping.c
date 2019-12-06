#include <ansi.h>

inherit ROOM;
string* flowers = ({
	__DIR__"obj/hua",
	__DIR__"obj/hua",
	__DIR__"obj/hua3",
	__DIR__"obj/hua2",
	__DIR__"obj/hua3",
	__DIR__"obj/hua4",
});
string* npcs = ({
	__DIR__"npc/boy",
	__DIR__"npc/boy2",
	__DIR__"npc/boy3",
	__DIR__"npc/boy4",
	__DIR__"npc/girl",
	__DIR__"npc/boy",
	__DIR__"npc/boy2",
	__DIR__"npc/boy3",
	__DIR__"npc/boy4",
	__DIR__"npc/girl",
	__DIR__"npc/girl",
});

void create()
{
    set("short", "��ƺ");
    set("long", @LONG
������һƬ����Ĳ�ƺ,�м�����������ˣ.���ܿ����˸�ɫ��
�ʻ�,һ�����紵��,���µĿ����д������Ƶ����Ļ���.
LONG );
    set("exits", ([
		"east" : __DIR__"kongdi",
    ]));
    set("objects", ([
		npcs[random(sizeof(npcs))] : 1,
		npcs[random(sizeof(npcs))] : 1,
		npcs[random(sizeof(npcs))] : 1,
		npcs[random(sizeof(npcs))] : 1,
		flowers[random(sizeof(flowers))] : 1,
		flowers[random(sizeof(flowers))] : 1,
		flowers[random(sizeof(flowers))] : 1,
    ]));
    set("outdoors", "shenlong");
    setup();
}

int valid_leave(object me, string dir)
{
	if (objectp(present("duanchang", environment(me)))) 
	{
        if((int)this_player()->query_condition("flower_poison") < 10 ) {
		this_player()->apply_condition("flower_poison", 30);
        tell_object(me, HIG "��ֻ��һ�ɵ���Ϯ��,��ʱ����һ����ľ��\n" NOR );
	}
	}
	return ::valid_leave(me, dir);
}
