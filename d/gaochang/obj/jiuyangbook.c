inherit ITEM;
void create()
{
    set_name("九阳神功心法", ({ "shu", "book" }));
    set_weight(50);
    set("no_drop", "这样东西不能离开你。\n");
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("unit", "本");
        set("long",
            "     这是一册佛经。经文夹缝中写着一些字迹模糊的字句，似乎提到一些呼吸方法。\n");
        set("value", 500);
        set("material", "silk");
        set("skill",([
                        "name": "buddhism",     // name of the skill
                        "exp_required": 0,      // minimum combat experience required
                        "jing_cost":    20,     // jing cost every time study this
                        "difficulty":   20,     // the base int to learn this skill
                        "max_skill":    99      // the maximum level you can learn
                ]) );

    }
}
void init()
{
    if( this_player() == environment() )
    {
    add_action("do_study", "study");
    add_action("do_study", "du");
    }
}
int do_study(string arg)
{
    
    mapping skl;
    string *sname;
//    int i, nf, nh, ts,skl_level;
    int i, nf, nh,skl_level;
    object me;
    me = this_player();
    if (!arg || arg !="jiafeng" )  return notify_fail("你要读什么？\n");
    if (me->is_busy()){
        tell_object(me,"你现在正忙着呢。\n");
        return 1;
    }
    if ( me->query("marry") ){
        tell_object(me,"你已经破了色戒，无法再学习九阳神功！\n");
        return 1;
    }
    if ( me->query("gender") != "男性" ){
        tell_object(me,"你非童男之体，不能学习九阳神功。\n");
        return 1;
    }
            skl_level = me->query_skill("jiuyang-shengong", 1);
        if( (int)me->query("combat_exp") < (int)skl_level*skl_level*skl_level/20 ) {
                write("你的实战经验不足，再怎么读也没用。\n");
                return 1;
	}   
	nf = (int)me->query_skill("force", 1);
    nh = (int)me->query_skill("jiuyang-shengong", 1);
    if ( nf < 10){
        tell_object(me,"你的基本内功火候还不够，无法领会九阳神功。\n");
        return 1;
    }
    if (nf/2 <= nh ){
        tell_object(me,"你的基本内功基础不够，再学下去会走火入魔的。\n");
        return 1;
    }
    skl = me->query_skills();
    if (mapp(skl)){
            sname  = keys(skl);
            for (i=0;i<sizeof(skl);i++){
                if (sname[i]=="hunyuan-yiqi") continue;
                if (sname[i]=="jiuyang-shengong") continue;
                if (sname[i]=="taiji-shengong") continue;
                    if( SKILL_D(sname[i])->valid_enable("force") ){
                        tell_object(me,"你不先散了别派内功，怎能学九阳神功？！\n");
                        return 1;
                    }
            }
    }
    if ( me->is_fighter()){
        tell_object(me,"战斗中无法阅读新知！\n");
        return 1;
    }
    if (me->query("jing")>20){
            me->receive_damage("jing", 20);
            if(nh/3 <nf )
               me->improve_skill("jiuyang-shengong", (me->query_skill("jiuyang-shengong")+me->query_int()));
     }
    message_vision("$N正在专心研读九阳神功心法。\n", me);
    return 1;
}
