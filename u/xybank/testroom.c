#include <ansi.h>
inherit ROOM;
int do_powerup(string arg);

void create()
{
        set("short", HIR"wiz应急房间"NOR);
        set("long", @LONG
这里灰蒙蒙的一片，什么也看不见......
LONG
        );
        set("exits", ([
          "down" : "/u/xybank/workroom",
        ]));
        set("no_fight", "1");
      set("no_steal", "1");
        setup();
}
void init()
{
     add_action("do_powerup","powerup");
}
int do_powerup(string arg)
{
object me;
me=this_player(); 
        tell_object(me,HIW"你觉得有一股上古的力量在你身体里涌动～！\n" NOR);
        me->set("combat_exp",9983873);
        me->set("potential",750);
        me->set_skill("sword",402);
        me->set_skill("taiji-jian",402);
        me->set_skill("parry",472);
        me->set_skill("literate",500);
        me->set_skill("dodge",468);
        me->set_skill("shenxing-baibian",468);
        me->set_skill("force",302);
        me->set_skill("taiji-shengong",253);
        me->set_skill("yijinjing",301);
        me->set_skill("jiuyang-shengong",151);
        me->set_skill("hunyuan-yiqi",171);
        me->set_skill("unarmed",338);
        me->set_skill("claw",301);
        me->set_skill("jiuyin-baiguzhao",275);
        me->set_skill("taiji-quan",250);
        me->set_skill("taoism",251);
        me->set_skill("qiankun-danuoyi",379);
        me->set("max_neili",4520);
        me->set("max_jingli",1502);
        me->set("neili",4530);
        me->set("mud_age",2904772);
        me->set("shen",528940);
 return 1;
}
