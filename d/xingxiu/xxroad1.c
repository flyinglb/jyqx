// Room: /d/xingxiu/xxroad1.c

inherit ROOM;

void create()
{
        set("short", "���");
        set("long", @LONG
������һ����ʯ����ϣ��������������һ����ǳأ�����
ǽ������Ʈ�������ǳ����ˡ�������ȥһƬ�����ͻ�Ұ��
LONG );
        set("exits", ([
            "east"  : "/d/city4/westgate",
            "west"  : __DIR__"xxroad2",
        ]));
        set("no_clean_up", 0);
        set("outdoors", "xingxiuhai");
        setup();
        replace_program(ROOM);
}

