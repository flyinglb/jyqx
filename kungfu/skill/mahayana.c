//mahayana.c  ������͹�
inherit SKILL;

string type() { return "knowledge"; }
int valid_learn(object me)
{
    mapping myfam;
    myfam = (mapping)me->query("family");
    if (!myfam || (myfam["family_name"] != "������"))
       return notify_fail("�㲻�Ƕ��ҵ��ӣ���������������͹���\n");

    if ((int)me->query("shen") < 0 )
       return notify_fail("���а��̫�أ��޷�����������͹���\n");

//    if (me->query_skill("persuading",1) <= me->query_skill("mahayana",1))
//       return notify_fail("�������̫�٣�����������͹�Ҳû�á�\n");

    if(me->query_skill("taoism",1) > 1)
       return notify_fail("������"+RANK_D->query_respect(me)
                   +"ѧ��ţ���ӵĹ�����ôȴ��ѧ������͹���\n");
    if( (int)me->query_skill("poison",1) > 1 )
      return notify_fail("��ѧ��а�Ŷ������޷�����������͹���\n");

    return 1;
}
void skill_improved(object me)
{}
