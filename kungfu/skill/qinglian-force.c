
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
        return notify_fail("清莲心法只能通过学(learn)来增加熟练度。\n");
}
