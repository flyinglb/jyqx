// baishulin1.c ������
// By Lgg,1998.10

inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
�ƹ������ȵ�ɽ�ڣ���ǰ��һƬ������֣���������ɽ�ڵ�ס��
���ߣ���ɽ�µ�ɽ·�ϸ����벻������İ�����������ô����ô�ߡ�
��̤���������У�����ȫ��ͷ������Ҷ��ס�ˣ�Խ�������������
Խ���İ���
LONG
        );
        set("outdoors", "quanzhen");
        set("exits", ([
                "southdown" : __DIR__"cuipinggu",
                "northup" : __DIR__"baishulin3",
                "east" : __DIR__"baishulin2",
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
