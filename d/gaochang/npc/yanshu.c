// laoshu.c ����
inherit NPC;
void create()
{
    set_name("����", ({ "yan shu", "shu", "mouse" }) );
    set("race", "Ұ��");
    set("age", 2);
    set("long", "һֻ�ɰ��ģ��������С����\n");
    set("attitude", "peaceful");
    
    set("limbs", ({ "ͷ��", "����", "ǰ��", "���", "β��" }) );
    set("verbs", ({ "bite", "claw" }) );
    set("combat_exp", 100);
    set("shen_type", -1);
    set("env/wimpy", 70);
    set("chat_chance", 10);
    
    set_temp("apply/attack", 5);
//  set_temp("apply/damage", 20);
    set_temp("apply/dodge", 20);
    set_temp("apply/armor", 1);
        set("chat_msg", ({
        "����֨֨���ؽ��˼�����\n",       
        "�����ڲݴ���������ȥ��\n",
        "��������ű������ţ��漴���˸������˽�ȥ! \n",
        (: random_move :)
        }) );
        setup();
}
