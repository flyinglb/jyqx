// qiankun-xinfa 乾坤大挪移心法
// by King 97.05
// Modify by risc 1/10/2001

#include <ansi.h>

inherit ITEM;
void setup()
{}

void init()
{
        add_action("do_kan","kan");
}

void create()
{
        set_name("羊皮", ({ "qiankunbook", "skin" }));
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "张");
                set("long", 
"这是一张羊皮，一面有毛，一面光滑。第一行是“明教圣
火心法，乾坤大挪移”十一个字。原来这就是武林第一秘
籍《乾坤大挪移》心法，相传来自西域山中老人所作。
想修这门绝世武功，就好好看(kan)这本书吧。\n");
                set("value", 50000);
                set("material", "paper");

        }
}

int do_kan(string arg)
{
        object me = this_player();
        object where = environment(me);
        int qklevel, lvl,neili_lost,jing_lost;
        int times;
        string tmp;

        if(!arg||(sscanf(arg, "%s %d", tmp,times)!=2 ))
            return notify_fail("指令格式：kan qiankunbook <次数>\n");
        if (tmp!="qiankunbook") return notify_fail("指令格式：kan qiankunbook <次数>\n");
        if (times>30 || times<1) return notify_fail("学习次数最少一次，最多也不能超过三十次。\n");
        if (where->query("pigging")) return notify_fail("你还是专心拱猪吧！\n");
        if (me->is_busy()) return notify_fail("你现在正忙着呢。\n");
        if( me->is_fighting() ) return notify_fail("你无法在战斗中专心下来研读新知！\n");
        if( !me->query_skill("literate", 1)) return notify_fail("你是个文盲，先学点文化(literate)吧。\n");
        
        if( (int)me->query("neili") < 1000 ) {
        write( HIC"忽然，你觉得内息一乱，知道不好！\n"NOR);
        me->unconcious();
        return 1;
        }
        if( !me->query_skill("jiuyang-shengong", 1) )
        return notify_fail("你没有九阳神功做根低，不能读乾坤大挪移。\n");

        jing_lost=40-(int)me->query("int");
        if( (int)me->query("jing") < times*jing_lost)
            return notify_fail("你现在过于疲倦，无法专心下来研读新知。\n");

        qklevel = me->query_skill("qiankun-danuoyi", 1);
        neili_lost = qklevel/10;
        if( neili_lost < 5) neili_lost = 5;
        lvl = qklevel/20;
        if( lvl < 1) lvl = 1;

        if ( me->query("gender") == "无性" && qklevel > 99)
            return notify_fail("你先天不足，再学下去难免走火入魔。\n");
        if ((int)me->query_skill("force", 1) < 150)
            return notify_fail("就这么点基本内功还想学乾坤大挪移？\n");
        if ((int)me->query("max_neili", 1) < 2500)
            return notify_fail("就这么点内力还想学乾坤大挪移？\n");
        if ((int)me->query_skill("force", 1) < lvl)
            return notify_fail("你的基本内功火候还不够，小心走火入魔！\n");
        if ((int)(me->query("max_neili", 1)/15) < lvl)
            return notify_fail("你的内力火候还不够，小心走火入魔！\n");
        if( (int)me->query("combat_exp") < (int)qklevel*qklevel*qklevel/10 )
            return notify_fail("你的实战经验不足，再怎么读也没用。\n");
            
        message("vision", me->name() + "专心研读乾坤大挪移，脸色忽青忽红，连变"+ 
                lvl + "次。\n", environment(me), me);
        me->receive_damage("jing", times*jing_lost);
        me->set("neili",(int)me->query("neili")-times*neili_lost);
        if( !me->query_skill("qiankun-danuoyi", 1) ) me->set_skill("qiankun-danuoyi", 0);
        me->improve_skill("qiankun-danuoyi", times*((int)me->query_skill("literate", 1)/3+1));
        write("你研读"+chinese_number(times)+"行《乾坤大挪移》心法，颇有心得。\n");
        return 1;
}
