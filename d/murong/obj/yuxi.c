// /u/beyond/mr/npc/obj/yuxi.c
// this is made by beyond
// update beyond
inherit ITEM;
#include <ansi.h>
void create()
{
       set_name(HIW"����"NOR, ({ "yu xi", "yuxi", "xi" }) );
       set_weight(100);
       if( clonep() )
               set_default_object(__FILE__);
      else {
               set("unit", "��");
               set("long", "����һ�������Ļʼ�������ȫ��͸������ɫ,������һ�ߺ�����һ˿�Ѻۡ�\n");
               set("value", 100000);
               set("no_get",1);                 
               set("no_give",1);
               set("treasure",1);
               set("no_put",1);
               set("no_drop",1);           
set("count",1);
               set("material", "jade");
       }
       setup();
}                   

void init()
{
        add_action("do_chou", "chou");
}

int do_chou()
{
	object me = this_player();
	object ob = this_object();
	if ( !present("yu xi",me) ) return 0;
	if ( me->query_temp("Ľ��/chou") < 1 ) {
		if ( ob->query("count") > 0 ) {
 			new(__DIR__"paper")->move(ob);
			message("vision","���һ��ֽ����������Сϸ���г��˳�����\n",me);
                        me->delete_temp("Ľ��/chou");
                        ob->add("count", -1);
			return 1;
		}
		else {
			write("����ϸ�ؿ����������죬��ȴʲôҲû���õ���\n",me);
			me->delete_temp("Ľ��/chou");
			return 1;
		}
		return 1;
	}
	
}	



