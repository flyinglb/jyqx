// Room: /u/mei/room40.c// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void init();
int do_out();
void create()
{
        set("short", "����");
        set("long", @LONG
��������ȺɽΧ�ƣ�����һֻ����һ�㣬�������ı�ˮӨȻ��������䣬��
��Բ�εĳ��ӣ�������ǧ���꣬��Ȼ�����ɿݣ������ص����л�ˮԴͷ���߽���
�ߣ�������ȥ��ֻ��������ǣ�˫������ˮ���������ξ��峺�������˺�̦�࣬
ԭ��Բ�����ܶ�����䣬��ˮ��ӳ����ɫ��ֻ����׵����ӳ�ڱ��̵ĳ��У���
�з��̣����з��ף����޽ྻ���ľ������
LONG
        );
        set("resource/water", 1);
        set("item_desc", ([
                "Բ��" : "���������������ʢ(fill)�������ĳ�ˮ��\n",
              "����" : "����������(out)��ϴ��Ү��\n",
        ]));

        set("exits", ([ 
        "up" : __DIR__"room39",
]));
//      set("outdoors", "room40");

        setup();
}
void init()
{
    add_action("do_out","out");
}
int do_out()
{
    object me = this_player();
    message_vision("$N���ܿ���һ�ۣ����ˡ���һ����������С�\n", me);
    me->move(__DIR__"room69");
    return 1;
}
