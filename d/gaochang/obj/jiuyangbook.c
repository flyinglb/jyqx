inherit ITEM;
void create()
{
    set_name("�������ķ�", ({ "shu", "book" }));
    set_weight(50);
    set("no_drop", "�������������뿪�㡣\n");
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("unit", "��");
        set("long",
            "     ����һ��𾭡����ļз���д��һЩ�ּ�ģ�����־䣬�ƺ��ᵽһЩ����������\n");
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
    if (!arg || arg !="jiafeng" )  return notify_fail("��Ҫ��ʲô��\n");
    if (me->is_busy()){
        tell_object(me,"��������æ���ء�\n");
        return 1;
    }
    if ( me->query("marry") ){
        tell_object(me,"���Ѿ�����ɫ�䣬�޷���ѧϰ�����񹦣�\n");
        return 1;
    }
    if ( me->query("gender") != "����" ){
        tell_object(me,"���ͯ��֮�壬����ѧϰ�����񹦡�\n");
        return 1;
    }
            skl_level = me->query_skill("jiuyang-shengong", 1);
        if( (int)me->query("combat_exp") < (int)skl_level*skl_level*skl_level/20 ) {
                write("���ʵս���鲻�㣬����ô��Ҳû�á�\n");
                return 1;
	}   
	nf = (int)me->query_skill("force", 1);
    nh = (int)me->query_skill("jiuyang-shengong", 1);
    if ( nf < 10){
        tell_object(me,"��Ļ����ڹ���򻹲������޷��������񹦡�\n");
        return 1;
    }
    if (nf/2 <= nh ){
        tell_object(me,"��Ļ����ڹ�������������ѧ��ȥ���߻���ħ�ġ�\n");
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
                        tell_object(me,"�㲻��ɢ�˱����ڹ�������ѧ�����񹦣���\n");
                        return 1;
                    }
            }
    }
    if ( me->is_fighter()){
        tell_object(me,"ս�����޷��Ķ���֪��\n");
        return 1;
    }
    if (me->query("jing")>20){
            me->receive_damage("jing", 20);
            if(nh/3 <nf )
               me->improve_skill("jiuyang-shengong", (me->query_skill("jiuyang-shengong")+me->query_int()));
     }
    message_vision("$N����ר���ж��������ķ���\n", me);
    return 1;
}
