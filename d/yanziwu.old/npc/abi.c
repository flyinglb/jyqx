// abi.c

inherit NPC;

void create()
{
        set_name("����", ({ "abi", "bi" }));
        set("long",
                "���Ǹ������µ�Ů�ɣ�Լʮ��������ͣ������������ᣬ\n"
                "������������һ�ſɰ��Ĺ��������������°���ź��˵��\n"
                "���������壬����һ��֮��˵���������ʡ���Ǳ�һ��ϸ\n"
                "ϸ�ĺ��̣��������ġ�\n");
        set("gender", "Ů��");
        set("age", 16);
        set("shen_type", 1);

        set("neili", 200);
        set("max_neili", 200);
        set("max_qi", 160);
        set("max_jing", 160);
        set_skill("force", 40);
        set_skill("unarmed", 40);
        set_skill("dodge", 30);
        set_skill("parry", 30);
        set_skill("sword", 30);
        set_temp("apply/attack", 10);
        set_temp("apply/defense", 10);
        set_temp("apply/damage", 5);

        set("combat_exp", 10000);
        set("inquiry",([
            "����ɽׯ" : "�ҲŲ���ȥ����ɽׯ��������̫�Ե���!\n",
            "������"   : "����ֻ��������������ǹ��ӣ�Ҳ��֪��������ô����!\n",
            "����"     : "��С����ֻ����һ�꣬�����ϲ��������档\n",
        ]) );
        setup();
        setup();
        carry_object(__DIR__"obj/goldring")->wear();
        carry_object(__DIR__"obj/necklace")->wear();
        carry_object(__DIR__"obj/changjian")->wield();
        carry_object(__DIR__"obj/green_cloth")->wear();
        carry_object(__DIR__"obj/flower_shoe")->wear();
}
