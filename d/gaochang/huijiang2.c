// Room: /d/xingxiu/xxroad7.c
inherit ROOM;
void create()
{
        set("short", "���׶���ԭ");
        set("long", @LONG
���������Ͻ��ˡ����صĵ��ƺ�����, ���γ����Ͻ��ѵ�һ����СƬ��
ԭ������ɽ��ס�˱�������, �������ḻ, �۾��˲��ٹ��������ˡ���˹
����Ҳ�����˵ط���������
LONG
        );
        set("exits", ([
            "northup" : __DIR__"huijiang1",
			"southwest" : "/d/xingxiu/luzhou",
            "southdown" : __DIR__"huijiang3",
            "eastdown" : __DIR__"huijiang5",
        ]));
        set("objects", ([
                __DIR__"npc/hasake"  : 1,
                __DIR__"npc/yang"  : 3,
        ]) );
        set("no_clean_up", 0);
        set("outdoors", "xingxiuhai");
        setup();
        replace_program(ROOM);
}
