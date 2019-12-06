// iceforce.c2
inherit FORCE;
int valid_enable(string usage) { return usage=="force"; }
int valid_learn(object me)
{
    mapping skl;
    string *sname;
    int i;
    int lvl = (int)me->query_skill("iceforce", 1);
    if ( me->query("gender") != "Ů��")
        return notify_fail("�⺮����һ��������ڹ���ֻ�ʺ�Ů��ѧ��\n");
    if (me->query_skill("force",1)<=lvl)
        return notify_fail("��Ļ����ڹ�������������ѧ��ȥ���߻���ħ�ġ�\n");
    if (me->query_skill("force",1)<20)
        return notify_fail("��Ļ����ڹ���������������ѧ�⺮�񹦡�\n");
    skl = this_player()->query_skills();
    sname  = keys(skl);
    for (i=0;i<sizeof(skl);i++){
        if (sname[i]=="iceforce") continue;
        if (sname[i]=="yijing-force") continue;
            if( SKILL_D(sname[i])->valid_enable("force") )
            return notify_fail("�㲻��ɢ�˱����ڹ�������ѧ�⺮�񹦣���\n");
    }
    return 1;
}
int practice_skill(object me)
{
        return notify_fail("�⺮��ֻ����ѧ�ģ����Ǵ�����(exert)�����������ȡ�\n");
}
string exert_function_file(string func)
{
    return __DIR__"iceforce/" + func;
}
mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
        mixed foo;
        foo = ::hit_ob(me, victim, damage_bonus, factor);
        if( intp(foo) && (damage_bonus + foo > 0) ) {
                if( random(me->query_skill("iceforce")) > (damage_bonus + 
foo) ) {
                        victim->receive_wound("qi", (damage_bonus + foo));
                        victim->apply_condition("iceshock", factor/3);
                        return "$N����ʽЮ��һ�������ޱȵľ���ʹ��$n�������˸����䡣\n";
                }
        }
        return foo;
}
 
