// parry.c
inherit SKILL;
string *parry_msg = ({
        "ֻ�������ϡ�һ������$p������$i���ˡ�\n",
        "�����������һ����$p�����ˡ�\n",
        "���Ǳ�$n������$i�ܿ���\n",
        "����$n����һ�࣬������$i�񿪡�\n",
});
string *unarmed_parry_msg = ({
        "���Ǳ�$p���ˡ�\n",
        "�����$p�����ˡ�\n",
});
string *no_weapon_msg = ({
        "���Ǳ�$p����һ�ƣ�$wʧ��׼ͷ����$p��$lƫ�˼��硣\n",
        "$p��$N����������һ�������$wƫ��һ�ߡ�\n",
});
string query_parry_msg(object me,object weapon)
{
    string msg;
    object my_weapon;
    
    if (!objectp(my_weapon=me->query_temp("weapon")) ){
        if (!objectp(my_weapon=me->query_temp("secondary_weapon")) ){
            if (weapon)
                return no_weapon_msg[random(sizeof(no_weapon_msg))];
            else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
        }
    }
    if (my_weapon->query("skill_type")=="throwing")
        if (weapon)
            return no_weapon_msg[random(sizeof(no_weapon_msg))];
        else
            return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
    msg=parry_msg[random(sizeof(parry_msg))];
    msg=replace_string( msg, "$i", my_weapon->name() );
    return msg;
}

