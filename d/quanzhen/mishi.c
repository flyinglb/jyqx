// mishi.c ����
// By Lgg,1998.10

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
������ȫ��̵���Ϊ��ֱ����ԭ�޽������ң�����Ĺ��߷ǳ�
�谵��Ҳ���Ѿ��������ˡ�
LONG
        );
        set("exits", ([
                "up" : __DIR__"diziju",
                "eastup" : "/d/city/guangchang",
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

