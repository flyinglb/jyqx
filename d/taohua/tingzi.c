inherit ROOM;

void create()
{
    set("short", "�Խ�ͤ");
    set("long",@LONG
������һ���ð���ʯ���ɵ�ͤ�ӣ�ͤ������С�����磬ʮ�־��ɡ�
ͤ�ӵı�����һƬ�һ��֣����������һ�ɽׯ�����š�
LONG);
    set("exits", ([
        "south" : __DIR__"damen",
        "north" : __DIR__"tao_out",
    ]));
    set("outdoors", "taohua");
    set("no_clean_up", 0);
    setup();
    replace_program(ROOM);
}
