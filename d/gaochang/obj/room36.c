// Room: /u/mei/room36.c
// This is a room made by roommaker. write by Fan. :)
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
        __DIR__"skeleton" : random(6)+1,
        __DIR__"skeleton1" : 1,
        __DIR__"yusword" : 2,
        __DIR__"yublade" : 2,
        __DIR__"yuaxe" : 2,
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
        add_action("do_study", "study");

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
int do_study(string arg)
{
        object me;
        int    jing_cost;
        me = this_player();

       if (!me->query_temp("���"))
               return notify_fail("��Ҫ��ʲô1��");
               if ( !arg || ( arg != "zhu jian" ) )
                    return notify_fail("��Ҫ��ʲô2��");

        if ( (int)me->query_skill("literate", 1) < 1){
                write("���Ǹ���ä����ѧ���Ļ�(literate)�ɡ�\n");
                return 1;
        }

        if ( (int)me->query_int() < 55){
                write("������Բ�������ѧ���Ļ�(literate)�ɡ�\n");
                return 1;
        }
        jing_cost = me->query("max_jing")/5;
        if((int)me->query("jing") < jing_cost){
                write("�㿴�˿����ϵ�����ƺ������һЩ������\n");
                return 1;
        }
        me->receive_damage("jing", jing_cost );
        me->delete_temp("stone_learned");

        message_vision("$N��ר���ж����ϵ����\n", me);
        
        write("����������ĥ��һ�ض�����������\n");

        if ( (int)me->query_skill("axe", 1) < 450 && random(10)>3 ){
                        me->improve_skill("axe", me->query_int());
                        me->set_temp("stone_learned",1);
                }
        return 1;
}

