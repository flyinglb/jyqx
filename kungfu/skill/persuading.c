// persuading.c

inherit SKILL;

string type() { return "knowledge"; }

void skill_improved(object me)
{}

int valid_learn(object me)
{
        return notify_fail("��������Ҫ��ʵ������ߡ�\n");
}
