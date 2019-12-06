// jinshe3.c
// modify by risc 1/10/2001
inherit ITEM;
inherit F_UNIQUE;
#include <ansi.h>; 
void setup()
{}
void init()
{
        add_action("do_kan", "kan");
}
void create()
{
        set_name(YEL"「金蛇秘芨」"NOR"下册", ({ "jinshe-book3","book3", }));
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("material", "paper");
                set("no_drop", "这样东西不能离开你。\n");
                set("no_get", "这样东西不能离开那儿。\n");
                set("no_put", "这样东西不能放在那儿。\n");
                set("long",
        "这是一本用薄纸写成的书。上书：「金蛇秘芨」。\n"
        "书皮泛黄，看来已经保存很久了。(也许值得kan)\n");
        }
}

int do_kan(string arg)
{
        object me = this_player();
        object where = environment(me);
        int pxlevel; 
        int neili_lost,jing_lost,times;
        string tmp;

        if(!arg || (sscanf(arg, "%s %d", tmp,times)!=2 )) 
            return notify_fail("指令格式：kan jinshe-book3 <次数>\n");

        if (tmp!="jinshe-book3") return notify_fail("指令格式：kan jinshe-book3 <次数>\n");
        if (times>30 || times<1) return notify_fail("学习次数最少一次，最多也不能超过三十次。\n");
        if (where->query("pigging")) return notify_fail("你还是专心拱猪吧！\n");
        if (me->is_busy()) return notify_fail("你现在正忙着呢。\n");
        if( me->is_fighting() ) return notify_fail("你无法在战斗中专心下来研读新知！\n");
        if( !me->query_skill("literate", 1)) return notify_fail("你是个文盲，先学点文化(literate)吧。\n");

        pxlevel = me->query_skill("jinshe-zhang", 1);
        if( (int)me->query("combat_exp") < (int)pxlevel*pxlevel*pxlevel/10 )
            return notify_fail("你的实战经验不足，再怎么读也没用。\n");
        if( me->query_skill("jinshe-zhang", 1) > 199)
            return notify_fail("你研读了一会儿，但是发现上面所说的对你而言都太浅了，没有学到任何东西。\n");

        message("vision", me->name() + "正专心地研读"YEL"金蛇密芨。\n"NOR, environment(me), me);
        write("你开始研读金蛇密芨。\n"NOR,);

        neili_lost = 5;
        if( (int)me->query("neili") < neili_lost*times) 
        return notify_fail("你内力不够，无法钻研这么高深的武功。\n");
        jing_lost = 15;
        if( (int)me->query("jing") < jing_lost*times )
        return notify_fail("你现在过于疲倦，无法专心下来研读新知。\n");

        me->receive_damage("jing", times*jing_lost);
        me->set("neili",(int)me->query("neili")-times*neili_lost);
        me->improve_skill("jinshe-zhang", times*((int)me->query_skill("literate", 1)/3+1));
        write(HIC"你研读了"+chinese_number(times)+"行金蛇密芨，颇有心得。\n"NOR,);
        return 1;
}
