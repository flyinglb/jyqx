// fangzhenqiao.c ������
// By Lgg,1998.10

inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
���ʯ�ף���ǰ��һ��ʯͷ���ɵ�СС���š����������ϵ�����
����������������ɽ�Ʒǳ�����������һ�������±��������°�
��Ʈ�����治֪���ںξ���
LONG
        );
        set("outdoors", "quanzhen");
        set("exits", ([
                "north" : __DIR__"yuzhengong",
                "southdown" : __DIR__"shijie7",
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
