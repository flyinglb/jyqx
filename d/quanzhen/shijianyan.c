// shijianyan.c �Խ���
// By Lgg,1998.10

inherit ROOM;

void create()
{
        set("short", "�Խ���");
        set("long", @LONG
ʯ��������һ�����ʯ������߲߰����ľ��ǿ��ˡ�������
ʯ����ȫ��̵��Խ��ң����µ�Ӣ��������������ȱ�������ʱ
����ʯ�ϵĿ��ۣ��޲���Ȼ�𾴡�
LONG
        );
        set("outdoors", "quanzhen");
        set("exits", ([
                "northdown" : __DIR__"shijie4",
                "southup" : __DIR__"shijie8",
                "east" : __DIR__"jiaobei",
        ]));
        set("objects",([
                __DIR__"npc/yin" : 1,
                __DIR__"npc/daotong" : 2,
        ]));

        setup();
        replace_program(ROOM);
}
