// qlist1500.c
inherit SKILL;

mapping *quest = ({
        ([      "quest":                "ţƤ�ƴ�",
                "quest_type":           "Ѱ",
                "time":                 200,
                "exp_bonus":            4,
                "pot_bonus":            2,
                "score" :               20
        ]),
        ([      "quest":                "����",
                "quest_type":           "Ѱ",
                "time":                 180,
                "exp_bonus":            4,
                "pot_bonus":            3,
                "score" :               20
        ]),
        ([      "quest":                "��Ʀ",
                "quest_type":           "ɱ",
                "time":                 280,
                "exp_bonus":            10,
                "pot_bonus":            4,
                "score" :               20
        ]),
        ([      "quest":                "С��",
                "quest_type":           "ɱ",
                "time":                 380,
                "exp_bonus":            15,
                "pot_bonus":            7,
                "score" :               20
        ]),
        ([      "quest":                "����",
                "quest_type":           "ɱ",
                "time":                 280,
                "exp_bonus":            10,
                "pot_bonus":            4,
                "score" :               20
        ]),
        ([      "quest":                "������Ů",
                "quest_type":           "ɱ",
                "time":                 280,
                "exp_bonus":            10,
                "pot_bonus":            4,
                "score" :               20
        ]),
        ([      "quest":                "�ο�",
                "quest_type":           "ɱ",
                "time":                 450,
                "exp_bonus":            15,
                "pot_bonus":            5,
                "score" :               20
        ]),
        ([      "quest":                "��å",
                "quest_type":           "ɱ",
                "time":                 180,
                "exp_bonus":            12,
                "pot_bonus":            5,
                "score" :               20
        ]),
        ([      "quest":                "�廨��",
                "quest_type":           "Ѱ",
                "time":                 180,
                "exp_bonus":            5,
                "pot_bonus":            3,
                "score" :               20
        ]),
        ([      "quest":                "С��",
                "quest_type":           "ɱ",
                "time":                 300,
                "exp_bonus":            6,
                "pot_bonus":            4,
                "score" :               20
        ]),
});

mapping query_quest()
{
        return quest[random(sizeof(quest))];
}
