#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "�����");
        set("long", @LONG
���С�ӽ��ں��ϣ�����ȥû��ʲô�ر�֮��������Ϊˮ��������
�������۵ס�Ψһ��ֵ����������һ������(qin)��
LONG );
        set("item_desc", ([
            "qin" : "���ٱ�֮Ѱ�������ٶ��˳���ȴ�оŸ����ҡ�\n"
                     "��֪�Ǹ�ȥ��һ��(tan)���ǽ�������(break)��\n",
        ]));
        set("exits", ([
            "south" : __DIR__"xiaoqiao",
        ]));
        set("no_clean_up", 0);
        setup();
}


void init()
{
    add_action("do_tan", "tan");
    add_action("do_tan","play");
    add_action("do_break","break");
}

int do_tan (string arg)
{
    object room;
    object ob = this_player();
    if (!arg||arg!="qin") return notify_fail("��Ҫ��ʲô��\n");
    message_vision("$N�����������һ��������һ����������Ϊ������\n\n"
                   +"�ƺ������е�Ź�.....\n"
                   +"$N�����Ƽ䣬�����ŵ�һ�飬��������ֱ��.....\n", ob );
    tell_object(ob, "\n���̲�ס��Ӵһ�����������һ������������ڣ�ԭ����һ��С����\n\n" ) ;
    room=load_object("d/yanziwu/hu");
    ob->move(room) ;

    call_out("mantuo", 10 , ob );
    return 1 ;
}

int do_break(string arg)
{
        if (!arg||arg!="qin") return notify_fail("��Ҫ����ʲô��\n");
        message_vision(
                "\n$Nһ�ƻ������٣�ֻ����ৡ���һ��,ͻȻ����һ����\n"+
                "һö÷����ٿ�����,���ۡ���һ��������$N������Ѩ��\n", this_player());
        if((int)this_player()->query("qi")<200) this_player()->die();
        else this_player()->unconcious();
        return 1;
}

int mantuo( object ob )
{
       tell_object(ob, "��������һ����֪���ĵط�,���µô���,"
                   +"ãȻ�Ŀ�������,��֪������\n") ;
//       ob -> move (__DIR__"chalin") ;
       ob -> move (__DIR__"hupan") ;
       return 1;
}

