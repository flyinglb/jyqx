#include <ansi.h>

inherit ROOM;

void create()
{
    set("short", "��Ժ");
    set("long", @LONG
����һ���ƾɵĴ�Ժ��Ժ�ӵ�ͦ�������������°�ʮ�ˡ�Ժ��
������һ�԰׵�(diao)��ԭ���������һ���Ϊ������ӻص�������
����ġ�
LONG );

    set("item_desc", ([
        "diao" : "һ�԰׵���չ�����ɡ�������һ����ĵ��ӣ�\n"
                  "����(ride)�Ϳ��Էɻ��һ�����\n",
    ]));
    set("exits", ([
		"north" : "/d/city/datiepu",
    ]));
    set("objects", ([
		CLASS_D("taohua")+"/lu" : 1,
    ]));
    set("outdoors", "taohua");
//    set("no_clean_up", 0);
    setup();
}

void init()
{
    add_action("do_ride", "ride");
}
int do_ride ( )
{
    mapping myfam;
    object room;
    object ob = this_player () ;
    myfam = (mapping)ob->query("family");
    if(!myfam || myfam["family_name"] != "�һ���")
    {
      message_vision("$NһԾ������˰׵�ֻ���׵����쳤ণ�ͻȻ��Ȼһ��......\n"
                     HIR "���$Nˤ�˸��������ף�\n" NOR
                     "�����׵��$N��������Ȥ����ֻ��ʶ�һ����ĵ��ӡ�\n" , ob ) ;
      ob -> receive_damage ("qi",50) ;
      ob -> receive_wound  ("qi",50) ;
      return 1;
    }
    if( !(room = find_object(__DIR__"lantian")) )
            room = load_object(__DIR__"lantian");
    if( room = find_object(__DIR__"lantian") ) 
    if((int)room->query_temp("tian_trigger")==1 ) 
     {
       message_vision("���ڰ׵���æ��,���һ���ٳ���!\n" , ob) ;
       return 1 ;
     }
    room->set_temp("tian_trigger", 1);
    message_vision("$NһԾ������˰׵�ֻ���׵����쳤ণ�ͻȻչ��߷ɡ�\n\n"
                   "����һ��һ�����ν�����С������������\n" , ob );
    ob->move(room) ;
    tell_object(ob, CYN  "\n�㲻�ϵط�ѽ�ɣ���ˮǧɽ����Ʈ�� ......\n\n" NOR ) ;
    call_out("taohua", 3 , ob );
    room->delete_temp("tian_trigger");
    return 1 ;
}
void taohua( object ob )
{
  tell_object(ob, "�����ڷɵ����һ�ɽׯ���׵�����������\n\n"  ) ;
  ob -> move (__DIR__"damen") ; 
}
void reset()
{
    object room;

    ::reset();
    if( room = find_object(__DIR__"lantian") )
        room->delete("tian_trigger"); 
}
