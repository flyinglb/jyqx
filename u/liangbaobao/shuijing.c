// shuijing

inherit ROOM;

void create()
{
        set("short", "����Ȫ");
        set("long", @LONG
        ����ǰ�У�һ·���̺���ϣ���ɽ��Ұ�����ʻ������������Ѽ���
ת��һ�����ԣ���ǰ����һ��Ȫˮ��Ȫˮ�峺���ף�ɢ����һ��������Ƣ�� 
������Ȫˮ���Աߣ�����һȺȺ�ĺ������򻨻�ף���ڻ��ϣ��������衣 
��������η�ˣ��ɽ�ʱ�������ǵ�����ͣ����
LONG );
        set("exits", ([
                "northwest" : __DIR__"guajia",
        ]));
        set("no_clean_up", 0);
        setup();
//      replace_program(ROOM);
}

void init()
{
        add_action("do_jump", "jump");
        add_action("do_zong", "zong");
}
int do_jump(string arg)
{
        object me;
        if (!arg ||arg !="down") return 1;
        me = this_player();
        message_vision("$N������ȥ��\n",me);
        me->move(__DIR__"wuchang3");
        message_vision("$N���˹�����\n",me);
        return 1;
}
int do_zong(string arg)
{
        object me;
        if (!arg ||arg !="shen") return 1;
        me = this_player();
        message_vision("$N������ȥ��\n",me);
        me->move(__DIR__"wuchang2");
        message_vision("$N���˹�����\n",me);
        return 1;
}

