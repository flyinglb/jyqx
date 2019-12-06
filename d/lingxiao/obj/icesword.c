//LUCAS 2000-6-18
#include <ansi.h>
#include <weapon.h>

inherit SWORD;

void create()
{
   set_name(HIW "����" NOR, ({"ice sword", "sword", "jian"}));
   set_weight(5000);
   set("unit", "��");
   set("long", "һ��ɢ����ɭɭ�����ı���,������֮������\n");
   set("value", 0);
   set("material", "ice");
   set("wield_msg",
"$N��ৡ���һ�����һ��$n�������У�ֻ��һ�ɺ������������\n");
   set("unwield_msg",
"$N�����е�$n�������䣬����ů�Ͷ��ˡ�\n");

   init_sword(50);

   if( clonep(this_object()) ) {
     set_default_object(__FILE__);
   }
   setup();
}  
void init()
{

   remove_call_out("do_melt");
   call_out("do_melt", 1);
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
        if(environment(env))
          message_vision("$N�������������ģ�ʪʪ�ģ�ԭ���Ǳ������ˡ�\n", env);
//        destruct(this_object());
        this_object()->move("/d/city/empty");
        return;
     }
   }

   else if( (int)env->query_max_encumbrance() > 0 && !environment(env) )
   {//a room.
     if( (string)env->query("outdoors") != "lingxiao" )
     {
        tell_object(env,"�������ڻ�����һ̲ˮ�����õ������ǡ�\n");
        destruct(this_object());
        this_player()->set("apply/damage",0);
        return;
     }
   } 
}


