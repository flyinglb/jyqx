// Room: /u/mei/room36.c

inherit ROOM;
#include <room.h>
void init();
int do_push(string arg);
int do_ketou(string);
int do_move(string);

void create()
{
    set("short", "���");
    set("long", @LONG
�ߵ���ڣ�ֻ�������Ҳ�������Ǻ��ǣ�����ɢ����һ�أ��������ձ����й�
һ����ս�����е��µ����Ǵ��СС��������������ǹ��ꪶ��У�ֻ����״���أ�
������ϰ������Ȼ��ͬ������ǰ����һ��ʮ�ֹ⻬��ʯ��(stone)��
LONG
    );
        set("objects", ([ 
        __DIR__"obj/skeleton" : random(6)+1,
        __DIR__"obj/skeleton1" : 1,
        __DIR__"obj/skeleton" : random(6)+1,
        __DIR__"obj/yusword" : 2,
        __DIR__"obj/yublade" : 2,
        __DIR__"obj/yuaxe" : 2,
]));
    set("exits", ([ 
        "west" : __DIR__"room35",
        "north" : __DIR__"room37",
]));
        set("item_desc", ([
        "stone" : 
"һ���м䰼����ȥ��ʯ�壬������ǰ���������������ͷ(ketou)��\n",
          ]));
    setup();
    set("move_zhujian",1);
}
void init()
{
        add_action("do_move", "move");
        add_action("do_ketou", "ketou");

}
int do_move(string arg)
{
        object me,ob;
        me = this_player();
        if ( !arg || arg!="skeleton" )
        return notify_fail("��Ҫ��ʲô��\n");  
        if( query("move_zhujian") ) {
        ob=new(__DIR__"obj/zhujian");
             write("��С������ؽ������ƿ�������������һ�����\n");
        ob->move(this_object());
        add("move_zhujian",-1);
             return 1;
       }else
       return 0;
}
int do_ketou(string arg)
{
        object me;
        string dir;
        me = this_player();
        if (!arg||arg=="") return 0; 
        if( arg=="stone" ) {
                message_vision("\n$N�������˿�ͷ���ƺ�ûʲô��Ӧ��\n", 
this_player());
        }
        if( sscanf(arg, "stone %s", dir)==1 ) 
        {
                if( dir=="4" || dir=="four") {               
                
message_vision("\n$N��ʯ�����������˿������£�$N��ǰһ�ڡ�\n", this_player());
                me->move(__DIR__"room73");
                }   
                else return 
notify_fail("\n����ҵؿ���ʯ�弸�£����ʲôҲû������\n");
        }               
        return 1;
}
