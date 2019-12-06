#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "�һ�ɽׯ����");
	set("long",@LONG
�������һ�ɽׯ�����š���ǰ�������µ����˼����һ���������
�ô˵����˶��һ���ƫ�����ſ�վ������Сͯ���ش��š��������ڵ�
����Զ�����̺��������Ƕ�ɽׯ�ķ��������ر��������ǰ��һ�԰�
��(diao)��
LONG);
	set("outdoors", "taohua");
	set("exits", ([
		"south" : __DIR__"qianyuan",
		"north" : __DIR__"tingzi",
		"east"  : __DIR__"road1" ,       
	]));
	set("item_desc", ([
		"diao" : "һ�԰׵���չ�����ɡ�������һ����ĵ��ӣ�\n"
		"����(ride)�Ϳ��Էɵ���ԭ��\n",
	]));
        set("objects", ([
                __DIR__"npc/shitong" : 2,
        ]));
//	set("no_clean_up", 0);
        set("outdoors", "taohua");
        setup();
}

void init()
{
    add_action("do_ride", "ride");
}
int do_ride ( )
{
    mapping myfam;
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
    if( (int)query("sb_ride") ) 
         return notify_fail("���ڰ׵���æ��,���һ���ٳ���!\n" ) ;
    add("sb_ride",1) ;
    message_vision("$NһԾ������˰׵�ֻ���׵����쳤ণ�ͻȻչ��߷ɡ�\n\n"
                   "����һ��һ�����ν�����С������������\n" , ob );
    ob->move("/d/taohua/lantian") ;
    tell_object(ob, CYN  "\n�㲻�ϵط�ѽ�ɣ���ˮǧɽ����Ʈ�� ......\n\n" NOR ) ;
    call_out("taohua", 3 , ob );
    add("sb_ride",-1) ;
    return 1 ;
}
void taohua( object ob )
{
  tell_object(ob, "�����ڷɵ�����ԭ���׵�����������\n\n"  ) ;
  ob -> move ("/d/guiyun/qianyuan");
}
