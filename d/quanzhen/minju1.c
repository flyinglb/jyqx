// minju1.c ���
// By Lgg,1998.10

inherit ROOM;

void create()
{
        set("short", "���");
        set("long", @LONG
�������һ�������ʵ��С���˼ң�����������ש������һ�׺�
ľ���Ρ�ǽ�Ϲ��ż���ɽˮ��(hua)�� ���˲��ڼ��
LONG
        );
        set("exits", ([
                "east" : __DIR__"beijie",
        ]));
        set("item_desc", ([
        "hua": "�ⲻ�Ǳ��η���ġ�Ϫɽ����ͼ��������һ�����������۾���ϸһ����ԭ���Ǹ���Ʒ��\n"
        ]) );
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
