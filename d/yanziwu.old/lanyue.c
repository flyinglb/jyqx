//ROOM: /d/yanziwu/lanyue.c

inherit ROOM;

void init();
int do_knock(string);
int do_say(string);
void reset();
void close(object);

void create()
{
        set("short", "���¾�");
        set("long",@LONG
����Ľ�ݹ��ӵ����ң����г�����ͨ����ʰ����Ϊ���࣬�ݽ�һ��
ï���辰(penjing)���ú�����ʢ�������¹�Ӵ�����������������⣬
���������һ��������
LONG );
        set("exits", ([
            "west": __DIR__"shuwu",
        ]));

        set("item_desc", ([
            "penjing" : "���辰�ƺ���ƽ��������������ر�⻬����һ�����ԣ�\n",
        ]));
        set("no_clean_up", 0);
        setup();
}
void init()
{
        add_action("do_knock","knock");
        add_action("do_say","say");
}
int do_knock(string arg)
{
        object me;
        me=this_player();

        if (!arg || (arg!="penjing" ) )
           return  notify_fail("��Ҫ��ʲô��\n");

        set_temp("marks/pen",1);
        message_vision("$NͻȻ���辰�����˼��£�$N����ѽ��\n",me);
        tell_object(me,"���������������˵�������������Ƕ���ʲô��û�а�������δ�˵���أ�\n");
        return 1;
}
int do_say(string arg)
{
        object me;
        me = this_player();

        if (!query_temp("marks/pen")) return 0;
        if( !arg || arg=="" ) return 0;

        if (arg == "�⸴����")
        {
                tell_object(me,"���Ȼ֪�����ţ������ǹ��ӽ������ģ��ͽ����ɡ�\n");
                message("vision", "�辰���ϵ�һ��ǽ�����ƿ���¶����ľ�š�\n", this_player());
                set("exits/east", __DIR__"huanshi");
                remove_call_out("close");
                call_out("close", 5, this_object());
                return 1;
        }
}

void close(object room)
{
        message("vision","��Ȼһ����Ӱ��������ľ�Ź����ˡ�\n", room);
        room->delete("exits/east");
}
void reset()
{
        ::reset();
        delete_temp("marks/pen");
}

