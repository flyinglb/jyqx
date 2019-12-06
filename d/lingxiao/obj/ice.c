//COPY �� XYJ ѩɽ������
//���³���һ�ң��㳭�ҳ���ҳ����ٺ١���
//LUCAS :)

#include <ansi.h> 
#include <weapon.h> 
inherit SWORD;


int do_make(string);

void create()
{
   set_name(HIW "����" NOR, ({ "bing zhu", "bing", "ice" }) ); 
   set_weight(5000); 
   if (clonep())  
        set_default_object(__FILE__); 
   else { 
        set("unit", "��"); 
        set("long",     "����һƬ�����ı���,��������Ө��͸,�����ޱ�,��֪���ܲ��ܳԡ�\n");
        set("unit", "Ƭ" ); 
        set("value", 8); 
        set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n"); 
        set("unwield_msg", "$NС�Ľ����е�$n�Żػ��С�\n");
        set("material", "ice");
   } 
        init_sword(25);
        setup(); 
}
void do_melt()
{
   if(this_object()) call_out("melt", 40+random(40));
}

void melt()
{
   object env;

        if(!this_object()) return;

   env=environment(this_object());

   if( env->is_character() )
   {//a player or a NPC.
     if( (int)env->query_skill("bingxue-xinfa", 1) < 20 )
     {
        message_vision("$N�������������ģ�ʪʪ�ģ�ԭ���Ǳ������ˡ�\n", env);
        destruct(this_object());
        return;
     }
   }

   else if( (int)env->query_max_encumbrance() > 0 && !environment(env) )
   {//a room.
     if( (string)env->query("outdoors") != "lingxiao" )
     {
        tell_object(env,"�������ڻ�����һ̲ˮ�����õ������ǡ�\n");
        destruct(this_object());
        return;
     }
   }

}

void init()
{                                             
        remove_call_out("do_melt");
        call_out("do_melt", 1);
   add_action("do_make", "make");
   add_action("do_make", "zuo");
   add_action("do_chi", "chi");
   add_action("do_chi", "eat");
}

int do_make(string arg)
{
   object ob, me;

   me = this_player();

   if( !arg || (arg != "sword" && arg != "jian" ) )
     return notify_fail("��Ҫ��ʲô��\n");

   if( (int)me->query("neili") < 200 || (int)me->query_skill("bingxue-xinfa", 1) < 20 )
   {
     message_vision("$N�������������ȥ����������ܿ�ͻ����ˡ�\n", me);
     destruct(this_object());
     return 1;
   }   

   ob=new("/d/lingxiao/obj/icesword");
   ob->move(me);
   me->add("neili", -100);
   message_vision(HIW"$N�������,���˱�ѩ�ķ�,ֻ������͸��һ������,��Ȼ�����
һ�ѽ���\n"NOR, me);
   destruct(this_object());

   return 1;
}

int do_chi(string arg)
{   
   if( !this_object()->id(arg) ) return 0;
   if( this_player()->is_busy() )
     return notify_fail("����һ��������û����ɡ�\n");

   if(!arg) return notify_fail("��Ҫ��ʲô��\n");

   message_vision( "$N�������ʹ��һҧ��ֻ�����գ�һ���������ˡ�\n" , this_player());
   if( (int)this_player()->query("qi") > 20 )
     this_player()->add("qi", -20);
   else this_player()->unconcious();

   return 1;
}

