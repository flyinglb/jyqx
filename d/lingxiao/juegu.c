//LUCAS 2000-6-18
// Room: juegu.c

inherit ROOM;
void create()
{
        set("short","����");
        set("long",@LONG
���ã��������ã���������Ԩ��ˤ��������Ȼˤ������
ѩ���ϣ�����û�����ٸ첲����Ƥ��û�˵�һ�㡣���ǣ�����
�����֮�£������ȥ��?����(pan)����?
LONG);
        set("outdoors", "lingxiao");
        set("exits", ([
        ]));
        set("no_clean_up", 0);
        setup();
} 

void init()
{
    add_action("do_pan","pan");
}
int do_pan()
{
        object me = this_player();
    me->move(__DIR__"shiya");
    return 1;
}

