// minju3.c ���
// By Lgg,1998.10

inherit ROOM;

void create()
{
        set("short", "���");
        set("long", @LONG
����һ�������ӣ����ζ��ܾ��ˣ����ҿ��ó������Լ����ô��
��ƴ�������ģ��������õúܸɾ���ǽ����б����һ֧�Բ棬Ҳ�����
�����˻��Ǹ����Ը��֡�
LONG
        );
        set("exits", ([
                "southeast" : __DIR__"guchang",
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
