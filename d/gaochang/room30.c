inherit ROOM;
void init();
int do_push(string);
int do_move(string);
void create()
{
        set("short", "���ɽ");
        set("long", @LONG
ɽ�����и���ۼ����쿴��ڣ����ڵĺۼ��������ԣ�ֻ�������¾ã�
����(men)�����ѱ�ɳ��(sand)������
LONG
        );
        set("outdoors", "room30");
        set("outdoors", "city");
        set("item_desc", ([
    "men" : "��ʯ�ſ��������أ��������Ƿ�����ƶ�(push)����\n",
    "sand" : "һЩɳ�ӡ�\n",
        ]));
        setup();
}
void init()
{
        add_action("do_climb", "climb");
        add_action("do_push", "push");
        add_action("do_move", "move");
}
int do_climb(string arg)
{
    object me;
    me = this_player();
    if( !arg || arg!="down") return notify_fail("��Ҫ���ĸ���������\n");
        me->move(__DIR__"room29");
        message("vision",
        me->name() + "սս��������������\n",
                environment(me), ({me}) );
        message("vision",
        me->name() + "սս����������������\n",
                environment(me), ({me}) );
    return 1;
}
int do_move(string arg)
{
        object me;
        me = this_player();
        if (!arg || arg !="sand" )
        return notify_fail("��Ҫ��ʲô��\n");
        write("ʯ���ƺ�����һ�¡�\n");
        this_player()->set_temp("marks/��1", 1);
        return 1;
}
int do_push(string arg)
{
        object me;
        object room;
        me = this_player();
    if (!arg || arg !="men"){
        write("��Ҫ��ʲô��\n");
        return 1;
    }
    if (!me->query_temp("marks/��1") ){
        write("��Ҫ��ʲô��\n");
        return 1;
    }
    if ((int)me->query_skill("force",1) < 250 ) {
        write("���ֻ��һ���ƺߣ��㱻ʯ�ڵķ����������ǰһ��....\n");
        message("vision",me->name()+"��Ȼһ�Σ���������׹ȥ���������׶༪����!\n",
            environment(me), ({me}) );
        me->move(__DIR__"room29");
            me->set("qi",-1);
        message("vision","�飡��һ���˵���������\n", environment(me));
        return 1;
    }
    if (!( room = find_object(__DIR__"room31")) )
            room = load_object(__DIR__"room31");
    this_player()->delete_temp("marks/��1");
    if (!query("exits/enter")){
            set("exits/enter", __DIR__"room31");
            message_vision("$N��ʯ���Ƶ�һ�ߣ�¶��һ�����ڣ�����ڳ�������ôҲ�Ʋ�����\n",me);
            room -> set("exits/out", __FILE__);
            message("vision", "���洫��һ���ƶ�ʯ�ŵ�¡¡��������\n",room);
            call_out("close_door",10);
            return 1;
    }
        write("��Ҫ��ʲô��\n");
        return 1;
}
void close_door()
{
        object room=find_object(__DIR__"room31");
        if (!room)
        room = load_object(__DIR__"room31");
        delete("exits/enter");
        message("vision","ʯ�ź�¡һ��������ԭ���������ֱ���ס�ˡ�\n",this_object());
        room -> delete("exits/out");
        message("vision","���洫��һ�����죬���ڱ���ס�ˡ�\n", room);
}
