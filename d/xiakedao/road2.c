// /d/xiakedao/road2.c ���͵� ɽ·2
inherit ROOM;

void create()
{
        set("short", "ɽ·");
        set("long", @LONG
С·�������۵�ͨ��ɽ�����Ų�������һȺ��������������
ʧ�ڿ��С�������ȴ��Щ������·�߲ݴԼ䲻ʱ����ɳɳ�����죬
�����Ƕ��ߣ����ǿ���뿪�ĺá�
LONG );
        set("outdoors", "xiakedao");
        set("exits", ([
                "southup" : __DIR__"road3",
                "northdown" : __DIR__"road1",
                ]));
        set("objects", ([
                "/d/shenlong/npc/dushe": 2,
        ]));
        setup();
        replace_program(ROOM);
}
