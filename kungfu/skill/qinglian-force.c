
inherit FORCE;
int valid_enable(string usage)
{
    return usage == "force";
}
int valid_learn(object me)
{
    return 1;
}

int practice_skill(object me)
{
        return notify_fail("�����ķ�ֻ��ͨ��ѧ(learn)�����������ȡ�\n");
}
