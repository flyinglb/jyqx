// kuihua-xinfa.c �����ķ�
inherit FORCE;
int valid_enable(string usage) { return usage == "force"; }
int valid_learn(object me)
{
    mapping skl;
    string *sname;

    int i = (int)me->query_skill("kuihua-xinfa", 1);
    int t = 1, j;
    for (j = 1; j < i / 10; j++) t*= 2;

    if ((string)me->query("gender") == "Ů��" ){
        tell_object(me, "�Թ�û��Ů�˿���ѧ�����ķ��ġ�\n");
        return 0;
        }
    if ((string)me->query("gender") == "����" ) {
        tell_object(me, "�����ķ���һҪ���������񹦣������Թ���\n");
        return 0;
        }

    if ((int)me->query_skill("force", 1) < 10){
        tell_object(me, "��Ļ����ڹ�����㣬����ѧ�����ķ���\n");
        return 0;
    }
    if (me->query_skill("force",1)<=i){
        tell_object(me, "��Ļ����ڹ�������������ѧ��ȥ���߻���ħ�ġ�\n");
        return 0;
    }
    if ( me->query_skill("buddhism",1) ){
        tell_object(me, "������ͺ¿�ǵ��ķ�����ѧ�����ķ���ʲ�ᣡ\n");
        return 0;
    }
    skl = me->query_skills();
    sname  = keys(skl);
    for (i=0;i<sizeof(skl);i++){
       if (sname[i]=="taixuan-gong") continue;
       if (sname[i]=="kuihua-xinfa") continue;
       if( SKILL_D(sname[i])->valid_enable("force") )
           { tell_object(me,"�㲻��ɢ�˱����ڹ�������ѧ�����ķ�����\n"); return 0; }
    }
    return 1;
}
int practice_skill(object me)
{
    return notify_fail("�����ķ�ֻ����ѧ(learn)�������������ȡ�\n");
}
string exert_function_file(string func)
{
    return __DIR__"kuihua-xinfa/" + func;
}

void skill_improved(object me)
{
        int s;
        s=me->query_skill("kuihua-xinfa",1);
    if (s%10==0) {
                tell_object(me, HIW"��Ŀ������Ѿ���������"+HIY+CHINESE_D->chinese_number(s/10)+HIW+"���ˡ�\n" NOR);
    }
}

