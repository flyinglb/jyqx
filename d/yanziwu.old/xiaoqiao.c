//ROOM: xiaoqiao.c

inherit ROOM;

void create()
{
        set("short", "������");
        set("long",@LONG
ϸ���͵�һ��СС���ţ����Ƶ����˵��б��µĻ��ƣ��ŵı���
������һ��ССľ�ݡ�վ�����ϣ�������Ŀ��������þò�Ը��ȥ��
LONG );
        set("outdoors", "yanziwu");
        set("exits", ([
            "north" : __DIR__"tingyu",
            "east"  : __DIR__"xiaojing",
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
