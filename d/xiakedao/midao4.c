// midao4.c �ܵ�

inherit ROOM;

int do_break(string arg);
void create()
{
        set("short", "�ܵ�");
        set("long", @LONG
����һ���ܳ�������ͨ���������Ǽ�Ӳ��ʯ�ڣ���ʲôҲ����
����ֻ������ǰ����ͻȻ���ߵ���·�ľ�ͷ�����Ǹ���·���㻹��
��ȥ�ɡ�
LONG );
        set("item_desc",([
            "shibi" : "��!ʯ����ʲô�ɿ��ģ���������ʯ�ں������Ĳ�ͬȴ����ġ�
ѽ������һ��ʯ��(men)��!\n",
        ]));
        set("exits", ([
                "east" : __DIR__"midao3",
        ]));
        set("no_clean_up", 0);
        setup();

}
void init()
{
        add_action("do_break","break");
}
int do_break(string arg)
{
        int n;
        n = this_player()->query("neili");
        if( !arg || arg!="men")
        {
            write("��Ҫ������Ʊ��˵Ķ�����\n");
            return 1;
        }
        message_vision("$N��ʯ��ǰվ��������һ����������ͬʱ�ĳ���\n", this_player());
        if (n >200)
        {
            message_vision("$N����һ�������͵�һ�ģ�ʯ�������Ŀ��ˡ�\n", this_player());
            set("exits/west",__DIR__"midao5");
            this_player()->set("neili",n-200);
            remove_call_out("close");
            call_out("close",5, this_object());
        }
        else
        {
            message_vision("$N����һ�������͵�һ�ģ�ʯ��ȴ˿��û����\n", this_player());
            this_player()->set("neili",0);
        }
        return 1;
}

void close(object room)
{
        message("vision","ʯ���Զ��ĺ����ˡ�\n", room);
        room->delete("exits/west");
}

