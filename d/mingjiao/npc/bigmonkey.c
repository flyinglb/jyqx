// bigmonkey.c

inherit NPC;

void create()
{
    set_name("���Գ", ({ "yuan", "dabai yuan", "big monkey" }) );
    set("gender", "����");
    set("race", "Ұ��");
    set("age", 65);
    set("long",
        "����һֻ���Գ����ֵ��Ǵ��������ŵõ�һ�󸯳�֮����ԭ����Գ����ŧѪ
ģ��������һ���󴯡�\n");
    set("combat_exp", 50000);
    set("shen_type", 1);
    set("attitude", "peaceful");
    set("limbs", ({ "Գ��", "ǰצ", "��צ", "β��" }) );
    set("verbs", ({ "bite", "claw" }) );

    set("water", 200);
    set("food", 200);

    set("apply/attack", 100);
    set("apply/defense", 100);

    set_skill("unarmed", 25);
    set_skill("parry", 20);
    set_skill("dodge", 20);
    set("bag_count",1);

    setup();
}
void init()
{
    add_action("do_lifeheal", "lifeheal");
}
int do_lifeheal(string arg)
{
    object weapon, bag, me = this_player();
    if (query("bag_count")<1)
    {
        write("��Գһ����������������ҽ�Σ�\n");
        return 1;
    }
    if( !arg || arg != "yuan")
    {
        write("�����ʲôѽ?\n");
        return 1;
    }
    if (!present("fish bone", me))
    {
        write("���ᣬ�ܿ������ܷ��Ƥ����\n");
        return 1;
    }
    if (!objectp(weapon = me->query_temp("weapon")) ||
        ((string)weapon->query("skill_type") != "sword" &&
         (string)weapon->query("skill_type") != "blade"))
         return notify_fail("��û�й������������������\n");

    message_vision(
"$N��ұ߼��϶˵ķ��ߣ���б���п���������ĸ�Ƥ��ֻ��������
�����һ���Ͳ�������$N���Ͳ�������һ�ߣ���������룬������Ƥ
�ϴ���һ����С�ף��ٽ���Ƥ˺��ϸ˿������С�״�ᣬ��ǿ����Գ
�ĸ�����ã��ڴ��ڷ��ϲ�ҩ��\n", me);
        bag = new("/d/mingjiao/obj/bag");
        bag -> move (environment(me));
        add("bag_count",-1);
        return 1;
}
