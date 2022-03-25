c V3toV4.cc Use this table to upgrade a dictionary
c from DDP version 3 to version 4.

group(1)
'\is ' > dup back(1) use(2)
group(2)
'\' > dup back(1) use(1)
' 1.1.1' nl > ' 1.1' nl c Objects in the sky
' 1.1.1.1' nl > ' 1.1.1' nl c Sun
' 1.1.1.2' nl > ' 1.1.1.1' nl c Moon
' 1.1.1.3' nl > ' 1.1.1.2' nl c Star
' 1.1.1.4' nl > ' 1.1.1.3' nl c Planet
' 1.1.3.1.1' nl > ' 1.1.2.1' nl c Blow air
' 1.2.2.6' nl > ' 1.2.3' nl c Solid, liquid, gas
' 1.2.2.7' nl > ' 1.2.3.1' nl c Liquid
' 1.2.2.8' nl > ' 1.2.3.2' nl c Oil
' 1.2.2.9' nl > ' 1.2.3.3' nl c Gas
' 2.1' nl > ' 4.1.2' nl c Types of people
' 2.2' nl > ' 2.1' nl c Body
' 2.2.1' nl > ' 2.1.1' nl c Head
' 2.2.2' nl > ' 2.1.2' nl c Torso
' 2.2.3' nl > ' 2.1.3' nl c Arm, leg
' 2.2.3.1' nl > ' 2.1.3.1' nl c Arm
' 2.2.3.2' nl > ' 2.1.3.2' nl c Leg
' 2.2.3.3' nl > ' 2.1.3.3' nl c Finger, toe
' 2.2.4' nl > ' 2.1.4' nl c Skin
' 2.2.5' nl > ' 2.1.5' nl c Hair
' 2.2.6' nl > ' 2.1.6' nl c Bone, joint
' 2.2.7' nl > ' 2.1.7' nl c Flesh
' 2.2.8' nl > ' 2.1.8' nl c Internal organs
' 2.2.8.1' nl > ' 2.1.8.3' nl c Male organs
' 2.2.8.2' nl > ' 2.1.8.4' nl c Female organs
' 2.3' nl > ' 2.2' nl c Body functions
' 2.3.1' nl > ' 2.1.1.1' nl c Functions of the eye
' 2.3.1.1' nl > ' 3.5.6.5' nl c Weep
' 2.3.2' nl > ' 2.1.1.2' nl c Functions of the ear
' 2.3.3' nl > ' 2.1.1.3' nl c Functions of the nose
' 2.3.4' nl > ' 2.1.1.4' nl c Functions of the mouth
' 2.3.4.1' nl > ' 2.2.3' nl c Spit, saliva
' 2.3.4.2' nl > ' 3.5.6.3' nl c Facial expression
' 2.3.5' nl > ' 2.1.8.1' nl c Functions of the heart
' 2.3.5.1' nl > ' 2.2.5' nl c Bleed, blood
' 2.3.6' nl > ' 2.2.1' nl c Breathe, breath
' 2.3.7' nl > ' 2.1.8.2' nl c Functions of the stomach
' 2.3.7.1' nl > ' 2.2.8' nl c Defecate, feces
' 2.3.8' nl > ' 2.2.7' nl c Urinate, urine
' 2.3.9' nl > ' 2.2.6' nl c Sweat
' 2.4' nl > ' 2.3' nl c The senses
' 2.4.1' nl > ' 2.3.1' nl c See
' 2.4.1.1' nl > ' 2.3.1.1' nl c Look
' 2.4.1.2' nl > ' 2.3.1.4' nl c Show, let someone see
' 2.4.1.3' nl > ' 2.3.1.9' nl c Something used to see
' 2.4.2' nl > ' 2.3.2' nl c Hear
' 2.4.2.1' nl > ' 2.3.2.2' nl c Sound
' 2.4.2.2' nl > ' 2.3.2.3' nl c Types of sounds
' 2.4.3' nl > ' 2.3.3' nl c Taste
' 2.4.4' nl > ' 2.3.4' nl c Smell
' 2.4.5' nl > ' 2.3.5' nl c Sense of touch
' 2.4.5.1' nl > ' 2.3.5.1' nl c Comfortable
' 2.5' nl > ' 2.4' nl c Body condition
' 2.5.1' nl > ' 2.4.4' nl c Tired
' 2.5.2' nl > ' 2.4.5' nl c Rest
' 2.5.3' nl > ' 2.4.1' nl c Strong
' 2.5.4' nl > ' 2.4.2' nl c Weak
' 2.6' nl > ' 2.5' nl c Healthy
' 2.6.1' nl > ' 2.5.1' nl c Sick
' 2.6.1.1' nl > ' 2.5.1.1' nl c Recover from sickness
' 2.6.2' nl > ' 2.5.2' nl c Disease
' 2.6.2.1' nl > ' 2.5.2.1' nl c Malnutrition, starvation
' 2.6.2.2' nl > ' 2.5.2.2' nl c Skin disease
' 2.6.2.3' nl > ' 2.5.2.2' nl c Leprosy
' 2.6.2.4' nl > ' 2.5.2.3' nl c Stomach illness
' 2.6.2.5' nl > ' 2.5.2.4' nl c Tooth decay
' 2.6.3' nl > ' 2.5.3' nl c Injured
' 2.6.3.1' nl > ' 2.5.3.1' nl c Amputation
' 2.6.3.2' nl > ' 2.5.3.2' nl c Poison
' 2.6.4' nl > ' 2.5.4' nl c Disabled
' 2.6.4.1' nl > ' 2.5.4' nl c Crippled
' 2.6.4.2' nl > ' 2.5.4' nl c Paralyzed
' 2.6.4.3' nl > ' 2.5.4.1' nl c Blind
' 2.6.4.4' nl > ' 2.5.4.2' nl c Poor eyesight
' 2.6.4.5' nl > ' 2.5.4.3' nl c Deaf
' 2.6.4.6' nl > ' 2.5.4.4' nl c Mute
' 2.6.4.7' nl > ' 2.5.8' nl c Mental illness
' 2.6.4.8' nl > ' 2.5.4.5' nl c Birth defect
' 2.6.5' nl > ' 2.5.6' nl c Symptoms of disease
' 2.6.5.1' nl > ' 2.5.6.1' nl c Pain
' 2.6.5.2' nl > ' 2.5.6.2' nl c Fever
' 2.6.5.3' nl > ' 2.5.6.3' nl c Swell
' 2.6.6' nl > ' 2.5.7' nl c Treat disease
' 2.6.6.1' nl > ' 2.5.7' nl c Care for a sick person
' 2.6.6.2' nl > ' 2.5.3.2' nl c Treat for poisoning
' 2.6.6.3' nl > ' 2.5.7.1' nl c Doctor, nurse
' 2.6.6.4' nl > ' 2.5.7.2' nl c Medicine
' 2.6.6.5' nl > ' 2.5.7.3' nl c Medicinal plants
' 2.6.6.6' nl > ' 2.5.7.4' nl c Hospital
' 2.6.6.7' nl > ' 2.5.7.5' nl c Traditional medicine
' 2.7' nl > ' 2.6' nl c Life
' 2.7.1' nl > ' 2.6.1' nl c Marriage
' 2.7.1.1' nl > ' 2.6.1.1' nl c Arranging a marriage
' 2.7.1.2' nl > ' 2.6.1.2' nl c Wedding
' 2.7.1.3' nl > ' 2.6.1.3' nl c Unmarried
' 2.7.1.4' nl > ' 2.6.1.4' nl c Divorce
' 2.7.1.5' nl > ' 2.6.1.5' nl c Romantic love
' 2.7.2' nl > ' 2.6.2' nl c Sexual relations
' 2.7.2.1' nl > ' 2.6.2.1' nl c Virginity
' 2.7.2.2' nl > ' 2.6.2.2' nl c Attract sexually
' 2.7.2.3' nl > ' 2.6.2.3' nl c Sexual misbehavior
' 2.7.3' nl > ' 2.6.3' nl c Birth
' 2.7.3.1' nl > ' 2.6.3.1' nl c Pregnancy
' 2.7.3.1.1' nl > ' 2.6.3.2' nl c Fetus
' 2.7.3.1.2' nl > ' 2.6.3.3' nl c Miscarriage
' 2.7.3.2' nl > ' 2.6.3' nl c Give birth
' 2.7.3.2.1' nl > ' 2.6.3.4' nl c Labor and birth pains
' 2.7.3.2.2' nl > ' 2.6.3.5' nl c Help to give birth
' 2.7.3.3' nl > ' 2.6.3.6' nl c Unusual birth
' 2.7.3.4' nl > ' 2.6.3.7' nl c Multiple births
' 2.7.3.5' nl > ' 2.6.3.9' nl c Birth ceremony
' 2.7.3.6' nl > ' 2.6.3.8' nl c Fertile, infertile
' 2.7.4' nl > ' 2.6.4' nl c Stage of life
' 2.7.4.1' nl > ' 2.6.4.1' nl c Baby
' 2.7.4.1.1' nl > ' 2.6.4.1.1' nl c Care for a baby
' 2.7.4.2' nl > ' 2.6.4.2' nl c Child
' 2.7.4.2.1' nl > ' 2.6.4.2.1' nl c Rear a child
' 2.7.4.3' nl > ' 2.6.4.3' nl c Youth
' 2.7.4.4' nl > ' 2.6.4.4' nl c Adult
' 2.7.4.5' nl > ' 2.6.4.5' nl c Older person
' 2.7.4.6' nl > ' 2.6.4.6' nl c Grow, get bigger
' 2.7.4.7' nl > ' 2.6.4.7' nl c Initiation
' 2.7.4.8' nl > ' 2.6.4.8' nl c Peer group
' 2.7.5' nl > ' 2.6.5' nl c Male, female
' 2.7.5.1' nl > ' 2.6.5.1' nl c Man
' 2.7.5.2' nl > ' 2.6.5.2' nl c Woman
' 2.7.6' nl > ' 2.6.6' nl c Die
' 2.7.6.1' nl > ' 2.6.6.1' nl c Kill
' 2.7.6.2' nl > ' 2.6.6.2' nl c Corpse
' 2.7.6.3' nl > ' 2.6.6.5' nl c Bury
' 2.7.6.4' nl > ' 2.6.6.6' nl c Grave
' 2.7.6.5' nl > ' 2.6.6.3' nl c Funeral
' 2.7.6.6' nl > ' 2.6.6.4' nl c Mourn
' 3.1.2.2' nl > ' 2.5.6.5' nl c Dazed, confused
' 3.1.2.3' nl > ' 2.5.6.4' nl c Lose consciousness
' 3.1.2.4' nl > ' 2.5.6.6' nl c Vision, hallucination
' 3.2' nl > ' 3.2.1' nl c Mind
' 3.2.1' nl > ' 3.2' nl c Think
' 3.2.2.6' nl > ' 3.1.2.2' nl c Notice
' 3.2.2.7' nl > ' 3.2.2.6' nl c Realize
' 3.2.2.8' nl > ' 3.2.2.7' nl c Willing to learn
' 3.2.4.3' nl > ' 3.5.8.1' nl c Meaning
' 3.3.3.2' nl > ' 3.3.3.3' nl c Persuade
' 3.3.3.3' nl > ' 3.3.3.2' nl c Advise
' 3.3.3.9' nl > ' 6.8.3.4' nl c Beg
' 3.3.4.4' nl > ' 7.2.6.2' nl c Restrain
' 3.3.4.5' nl > ' 3.3.4.4' nl c Prevent
' 3.3.4.6' nl > ' 3.3.4.5' nl c Free to do what you want
' 3.4.1.2.1' nl > ' 3.5.6.4' nl c Laugh
' 3.4.1.2.2' nl > ' 3.4.1.2.1' nl c Relaxed
' 3.4.1.2.3' nl > ' 3.4.1.2.2' nl c Calm
' 3.5.1.2' nl > ' 3.5.2' nl c Make speech
' 3.5.1.2.2' nl > ' 3.5.1.2.8' nl c Emphasize
' 3.5.1.2.3' nl > ' 3.5.1.2.5' nl c Introduce
' 3.5.1.2.4' nl > ' 3.5.1.2.6' nl c Repeat
' 3.5.1.2.5' nl > ' 3.5.1.2.7' nl c Summarize
' 3.5.1.4.2' nl > ' 3.5.1.4.3' nl c Greet
' 3.5.1.4.3' nl > ' 3.5.1.4.4' nl c Say farewell
' 3.5.1.4.4' nl > ' 3.5.1.4.5' nl c Speak in unison
' 3.5.2' nl > ' 3.5.2.1' nl c Report
' 3.5.2.1' nl > ' 3.5.2.2' nl c News, message
' 3.5.2.2' nl > ' 3.5.1.2.2' nl c Describe
' 3.5.2.3' nl > ' 3.5.1.3.6' nl c Exaggerate
' 3.5.2.4' nl > ' 3.5.2.3' nl c Figurative
' 3.5.2.5' nl > ' 3.5.3.2' nl c Information
' 3.5.2.6' nl > ' 3.5.2.4' nl c Admit
' 3.5.2.7' nl > ' 3.5.5' nl c Foolish talk
' 3.5.2.8' nl > ' 3.5.5.1' nl c Obscenity
' 3.5.4' nl > ' 3.5.4.6' nl c Verbal tradition
' 3.5.5' nl > ' 3.5.7' nl c Reading and writing
' 3.5.5.1' nl > ' 3.5.7.1' nl c Write
' 3.5.5.2' nl > ' 3.5.7.2' nl c Written material
' 3.5.5.3' nl > ' 3.5.7.3' nl c Read
' 3.5.5.4' nl > ' 3.5.7.4' nl c Publish
' 3.5.5.5' nl > ' 3.5.7.5' nl c Record
' 3.5.5.6' nl > ' 3.5.7.6' nl c List
' 3.5.7' nl > ' 3.5.8' nl c Interpreting messages
' 3.5.7.1' nl > ' 3.5.8.1' nl c Meaning
' 3.5.7.2' nl > ' 3.5.8.2' nl c Meaningless
' 3.5.7.3' nl > ' 3.5.8.3' nl c Unintelligible
' 3.5.7.4' nl > ' 3.5.8.4' nl c Show, indicate
' 3.5.8' nl > ' 3.5.9' nl c Mass communication
' 3.5.8.1' nl > ' 3.5.9.1' nl c Radio, television
' 3.5.8.2' nl > ' 3.5.9.2' nl c Telephone
' 3.5.8.3' nl > ' 3.5.9.3' nl c Newspaper
' 3.5.8.4' nl > ' 3.5.9.4' nl c Movie
' 3.5.8.5' nl > ' 3.5.9.5' nl c Recorded music
' 3.5.9' nl > ' 3.5.9.6' nl c Communication devices
' 3.6.4' nl > ' 3.6.5' nl c Correct
' 3.6.5' nl > ' 3.6.6' nl c Science
' 3.6.6' nl > ' 3.6.7' nl c Test
' 3.6.7' nl > ' 3.6.8' nl c Answer in a test
' 4.1.2' nl > ' 4.1.2.1' nl c Working relationship
' 4.2.6.1.1' nl > ' 4.2.6.4' nl c Gambling
' 4.2.6.2.3' nl > ' 4.2.6.2' nl c Sport#3
' 4.3.1.5.2' nl > ' 3.3.1.7' nl c Stubborn
' 4.3.1.5.3' nl > ' 4.3.1.5.2' nl c Bad-tempered
' 4.3.3.3' nl > ' 3.1.2.4' nl c Ignore
' 4.3.3.4' nl > ' 4.3.3.3' nl c Abandon
' 4.3.5.7' nl > ' 4.8.2.7' nl c Betray
' 4.4.2.7' nl > ' 4.4.2.6' nl c Suffer
' 4.5.4.1' nl > ' 4.5.4.3' nl c Serve
' 4.5.4.2' nl > ' 4.5.4.1' nl c Obey
' 4.5.4.3' nl > ' 4.5.4.2' nl c Disobey
' 4.5.4.4' nl > ' 4.5.4.6' nl c Rebel against authority
' 4.5.4.6' nl > ' 4.5.4.7' nl c Independent
' 4.5.5.1' nl > ' 4.5.5' nl c Posture of giving honor
' 4.5.5.2' nl > ' 4.5.5.1' nl c Title, name of honor
' 4.5.5.4' nl > ' 4.5.5.2' nl c Lack respect
' 4.6.6' nl > ' 4.8.2.7' nl c Hand over, betray
' 4.6.7' nl > ' 4.6.6' nl c Government functions
' 4.6.7.1' nl > ' 4.6.6.1' nl c Police
' 4.6.7.1.1' nl > ' 4.6.6.1.1' nl c Arrest
' 4.6.7.1.2' nl > ' 4.6.6.1.2' nl c Informal justice
' 4.6.7.2' nl > ' 6.8.8' nl c Tax
' 4.6.7.3' nl > ' 4.6.6.2' nl c Diplomacy
' 4.6.7.4' nl > ' 4.6.6.3' nl c Represent
' 4.6.7.5' nl > ' 4.6.6.4' nl c Election
' 4.6.7.6' nl > ' 4.6.6.5' nl c Political party
' 4.6.8' nl > ' 4.6.7' nl c Region
' 4.6.8.1' nl > ' 4.6.7.1' nl c Country
' 4.6.8.2' nl > ' 4.6.7.2' nl c City
' 4.6.8.3' nl > ' 4.6.7.3' nl c Countryside
' 4.6.8.4' nl > ' 4.6.7.4' nl c Community
' 4.7.5.4' nl > ' 4.8.2.4' nl c Defend
' 4.7.8.2' nl > ' 2.6.6.7' nl c Last will and testament
' 4.7.8.3' nl > ' 4.7.8.2' nl c Break a contract
' 4.8.1' nl > ' 4.8.2' nl c Fight someone
' 4.8.1.1' nl > ' 4.8.2.1' nl c Fight for something good
' 4.8.1.2' nl > ' 4.8.2.2' nl c Fight against something bad
' 4.8.1.3' nl > ' 4.8.2.3' nl c Attack
' 4.8.1.4' nl > ' 4.8.2.3.1' nl c Ambush
' 4.8.1.5' nl > ' 4.8.2.6' nl c Riot
' 4.8.1.6' nl > ' 4.7.9.6' nl c Persecute
' 4.8.1.7' nl > ' 2.5.3' nl c Harm, wound
' 4.8.1.8' nl > ' 4.8.2.8' nl c Violent, fierce
' 4.8.1.9' nl > ' 4.8.2.9' nl c Enemy
' 4.8.2' nl > ' 4.8.2.4' nl c Defend from attack
' 4.8.2.1' nl > ' 4.8.2.4' nl c Repulse
' 4.8.2.2' nl > ' 4.8.2.5' nl c Revenge
' 4.8.2.3' nl > ' 7.2.6.3' nl c Escape
' 4.8.2.4' nl > ' 7.2.6.4' nl c Set free
' 4.8.3' nl > ' 4.8.4' nl c Peace
' 4.8.3.1' nl > ' 4.8.4.1' nl c Rebuke
' 4.8.3.2' nl > ' 4.8.4.2' nl c Make an appeal
' 4.8.3.3' nl > ' 4.8.4.3' nl c Appease
' 4.8.3.4' nl > ' 4.8.4.4' nl c Negotiate
' 4.8.3.5' nl > ' 4.8.4.5' nl c Renounce claim, concede
' 4.8.3.6' nl > ' 4.8.4.6' nl c Repent
' 4.8.3.6.1' nl > ' 4.8.4.6.1' nl c Request forgiveness
' 4.8.3.7' nl > ' 4.8.4.7' nl c Forgive
' 4.8.3.8' nl > ' 4.8.4.8' nl c Make peace
' 4.8.3.8.1' nl > ' 4.8.4.8.1' nl c Stop fighting
' 4.8.3.9' nl > ' 4.8.4.9' nl c Reconcile
' 4.8.4' nl > ' 4.8.3' nl c War
' 4.8.4.1' nl > ' 4.8.3.1' nl c Defeat
' 4.8.4.2' nl > ' 4.8.3.2' nl c Win
' 4.8.4.3' nl > ' 4.8.3.3' nl c Lose a fight
' 4.8.4.4' nl > ' 4.8.3.4' nl c Surrender
' 4.8.4.5' nl > ' 4.8.3.6.4' nl c Soldier
' 4.8.4.5.1' nl > ' 4.8.3.6.5' nl c Spy
' 4.8.4.6' nl > ' 4.8.3' nl c Casualty
' 4.8.4.6.1' nl > ' 4.8.3.5' nl c Prisoner of war
' 4.8.4.7' nl > ' 4.8.3.6' nl c Military organizations
' 4.8.4.7.1' nl > ' 4.8.3.6.6' nl c Fort
' 4.8.4.8' nl > ' 4.8.3.7' nl c Weapon, Shoot
' 4.8.4.9' nl > ' 4.8.3.8' nl c Plunder
' 4.9.3' nl > ' 4.9.4' nl c Supernatural power
' 4.9.3.1' nl > ' 4.9.4' nl c Benevolent supernatural power
' 4.9.3.1.1' nl > ' 4.9.4' nl c Miracle
' 4.9.3.1.2' nl > ' 4.9.4.3' nl c Bless
' 4.9.3.2' nl > ' 4.9.4.1' nl c Malevolent supernatural power
' 4.9.3.2.1' nl > ' 4.9.4.2' nl c Demon possession
' 4.9.3.2.2' nl > ' 4.9.4.2' nl c Cast out demon
' 4.9.3.2.3' nl > ' 4.9.4.1' nl c Sorcery
' 4.9.3.2.4' nl > ' 4.9.4.4' nl c Curse
' 4.9.4' nl > ' 4.9.4.7' nl c Supernatural knowledge
' 4.9.4.1' nl > ' 4.9.4.6' nl c Prophecy
' 4.9.4.2' nl > ' 4.9.4.7' nl c Omen, divination
' 4.9.4.3' nl > ' 4.9.4.5' nl c Destiny
' 4.9.4.4' nl > ' 4.9.3' nl c Theology
' 4.9.4.5' nl > ' 4.9.3.1' nl c Sacred writings
' 5' nl > ' 6.5.1.1' nl c Home
' 5.1' nl > ' 6.5.2.7' nl c Rooms of a house
' 5.1.1' nl > ' 6.5.1.4' nl c Outside of a house
' 5.1.2' nl > ' 6.5.1.3' nl c Personal plot, property
' 5.1.3' nl > ' 5.1.1' nl c Furniture
' 5.1.3.1' nl > ' 5.1.1.1' nl c Table
' 5.1.3.2' nl > ' 5.1.1.2' nl c Chair
' 5.1.3.3' nl > ' 5.1.1.3' nl c Bed
' 5.1.3.4' nl > ' 5.1.1.4' nl c Cabinet
' 5.1.4' nl > ' 5.1' nl c Household tools
' 5.1.4.1' nl > ' 5.2.1.3' nl c Pot
' 5.1.5' nl > ' 5.1.2' nl c Household decorations
' 5.2.1.3' nl > ' 5.2.1.2' nl c Recipe
' 5.2.1.4' nl > ' 5.2.1.3' nl c Cooking utensils
' 5.2.1.5' nl > ' 5.2.1.4' nl c Food storage
' 5.2.1.6' nl > ' 5.2.1.5' nl c Serve food
' 5.2.2.1' nl > ' 5.2.2.2' nl c Meal
' 5.2.2.2' nl > ' 5.2.2.3' nl c Feast
' 5.2.2.3' nl > ' 5.2.2.4' nl c Manner of eating
' 5.2.2.4' nl > ' 5.2.2.5' nl c Hungry, thirsty
' 5.2.2.5' nl > ' 5.2.2.6' nl c Satiated, full
' 5.2.2.6' nl > ' 5.2.2.7' nl c Drink
' 5.2.2.7' nl > ' 5.2.2.8' nl c Eating utensil
' 5.2.2.8' nl > ' 5.2.2.9' nl c Fast, not eat
' 6.1.1.1' nl > ' 4.5.4.3' nl c Servant
' 6.1.1.2' nl > ' 4.5.4.4' nl c Slave
' 6.1.1.3' nl > ' 6.1.1.1' nl c Expert
' 6.2.5.2' nl > ' 6.2.4.2' nl c Uproot plants
' 6.2.5.3' nl > ' 6.2.5.2' nl c Crop failure
' 6.2.5.4' nl > ' 6.2.5.3' nl c Gather wild plants
' 6.2.5.5' nl > ' 6.2.5.4' nl c Plant product
' 6.5.1.1' nl > ' 6.5.1.2' nl c Types of houses
' 6.8.1.2' nl > ' 8.1.7' nl c Have sufficient
' 6.8.1.3' nl > ' 8.1.7.1' nl c Have extra
' 6.8.1.4' nl > ' 6.8.1.2' nl c Wealthy
' 6.8.1.5' nl > ' 8.1.7.2' nl c Have insufficient
' 6.8.1.6' nl > ' 6.8.1.3' nl c Poor
' 6.8.1.7' nl > ' 6.8.1.4' nl c Store wealth
' 6.8.1.8' nl > ' 6.8.1.5' nl c Possession, property
' 6.8.2.3' nl > ' 2.6.6.7' nl c Inherit
' 6.8.2.4' nl > ' 6.8.2.3' nl c Lose wealth
' 6.8.2.5' nl > ' 6.8.2.4' nl c Frugal
' 6.8.2.6' nl > ' 6.8.2.5' nl c Greedy
' 6.8.2.7' nl > ' 6.8.2.6' nl c Collect
' 6.8.9.4' nl > ' 6.8.9.1' nl c Embezzle
' 6.8.9.5' nl > ' 6.8.9.4' nl c Take by force
' 6.8.9.6' nl > ' 6.8.9' nl c Counterfeit
' 6.8.9.7' nl > ' 6.8.9.5' nl c Bribe
' 6.8.9.8' nl > ' 6.8.9.6' nl c Smuggle
' 7.2.4' nl > ' 7.2.5' nl c Accompany
' 7.2.4.1' nl > ' 7.2.5.1' nl c Go first
' 7.2.4.2' nl > ' 7.2.5.2' nl c Follow
' 7.2.4.3' nl > ' 7.2.5.3' nl c Guide
' 7.2.4.4' nl > ' 7.2.5.4' nl c Move together
' 7.2.5' nl > ' 7.2.6' nl c Flee, pursue
' 7.2.5.1' nl > ' 7.3.3.4' nl c Chase away
' 7.2.6' nl > ' 7.2.4' nl c Travel
' 7.2.6.1' nl > ' 7.2.4.1' nl c Travel by land
' 7.2.6.1.1' nl > ' 7.2.4.1.1' nl c Vehicle
' 7.2.6.1.2' nl > ' 7.2.4.1.2' nl c Railroad
' 7.2.6.2' nl > ' 7.2.4.2' nl c Travel by water
' 7.2.6.2.1' nl > ' 7.2.4.2.1' nl c Boat
' 7.2.6.2.2' nl > ' 7.2.4.2.2' nl c Swim
' 7.2.6.2.3' nl > ' 7.2.4.2.3' nl c Dive
' 7.2.6.3' nl > ' 7.2.4.3' nl c Travel by air
' 7.2.6.4' nl > ' 7.2.4.4' nl c Travel in space
' 7.2.6.5' nl > ' 7.2.4.5' nl c Move to a new house
' 7.2.6.6' nl > ' 7.2.4.8' nl c Map
' 7.2.7.4' nl > ' 7.2.6.2' nl c Prevent from moving
' 7.2.8' nl > ' 7.2.4.7' nl c Lose your way
' 7.2.9' nl > ' 7.2.8' nl c Send someone
' 7.3.3.4' nl > ' 7.4.1' nl c Give, hand to
' 7.3.3.5' nl > ' 7.4.2' nl c Receive
' 7.3.3.6' nl > ' 7.4.4' nl c Distribute
' 7.3.3.7' nl > ' 7.4.3' nl c Get
' 7.3.9' nl > ' 7.4.5' nl c Keep something
' 7.3.9.1' nl > ' 7.4.5.1' nl c Leave something
' 7.3.9.2' nl > ' 7.4.5.2' nl c Throw away
' 7.4' nl > ' 7.5' nl c Arrange
' 7.4.1' nl > ' 7.5.1' nl c Gather
' 7.4.1.1' nl > ' 7.5.1.1' nl c Separate, scatter
' 7.4.1.2' nl > ' 7.5.1.2' nl c Include
' 7.4.1.3' nl > ' 7.5.1.3' nl c Special
' 7.4.2' nl > ' 7.5.2' nl c Join, attach
' 7.4.2.1' nl > ' 7.5.2.1' nl c Link, connect
' 7.4.2.2' nl > ' 7.5.2.2' nl c Stick together
' 7.4.2.3' nl > ' 7.5.2.4' nl c Remove, take apart
' 7.4.3' nl > ' 7.5.3' nl c Mix
' 7.4.3.1' nl > ' 7.5.3.1' nl c Pure, unmixed
' 7.4.4' nl > ' 7.5.4' nl c Tie
' 7.4.4.1' nl > ' 7.5.4.1' nl c Rope, string
' 7.4.4.2' nl > ' 7.5.4.2' nl c Tangle
' 7.4.5' nl > ' 7.5.5' nl c Organize
' 7.4.5.1' nl > ' 7.5.5.1' nl c Disorganized
' 7.4.6' nl > ' 7.5.6' nl c Substitute
' 7.4.7' nl > ' 7.5.7' nl c Multiple things moving
' 7.4.8' nl > ' 7.5.8' nl c Simple, complicated
' 7.5' nl > ' 7.6' nl c Hide
' 7.5.1' nl > ' 7.6.1' nl c Search
' 7.5.2' nl > ' 7.6.2' nl c Find
' 7.5.3' nl > ' 7.6.3' nl c Lose, misplace
' 7.6' nl > ' 7.7' nl c Physical impact
' 7.6.1' nl > ' 7.7.1' nl c Hit
' 7.6.2' nl > ' 7.7.1' nl c Bounce
' 7.6.3' nl > ' 7.7.2' nl c Aim at a target
' 7.6.4' nl > ' 7.7.3' nl c Kick
' 7.6.5' nl > ' 7.7.4' nl c Press
' 7.6.6' nl > ' 7.7.5' nl c Rub
' 7.6.7' nl > ' 7.7.6' nl c Grind
' 7.6.8' nl > ' 7.7.7' nl c Mark
' 7.7' nl > ' 7.8' nl c Divide into pieces
' 7.7.1' nl > ' 7.8.1' nl c Break
' 7.7.2' nl > ' 7.8.2' nl c Crack
' 7.7.3' nl > ' 7.8.3' nl c Cut
' 7.7.4' nl > ' 7.8.4' nl c Tear, rip
' 7.7.5' nl > ' 7.8.5' nl c Make hole, opening
' 7.7.6' nl > ' 7.8.6' nl c Dig
' 7.7.7' nl > ' 7.9.1' nl c Damage
' 7.7.8' nl > ' 7.9.2' nl c Tear down
' 7.7.9' nl > ' 7.9.3' nl c Destroy
' 7.8' nl > ' 7.9' nl c Break, wear out
' 7.8.1' nl > ' 7.9.4' nl c Repair
' 8.1.1' nl > ' 8.1.2' nl c Count
' 8.1.1.1' nl > ' 8.1.2.1' nl c Arithmetic
' 8.1.1.2' nl > ' 8.1.2.2' nl c Add
' 8.1.1.3' nl > ' 8.1.2.3' nl c Subtract
' 8.1.1.4' nl > ' 8.1.2.4' nl c Multiply
' 8.1.1.5' nl > ' 8.1.2.5' nl c Divide
' 8.1.2' nl > ' 8.1.1' nl c Number
' 8.1.2.1' nl > ' 8.1.1.1' nl c Cardinal numbers
' 8.1.2.2' nl > ' 8.1.1.2' nl c Ordinal numbers
' 8.1.2.3' nl > ' 8.1.1.3' nl c Number of times
' 8.1.2.4' nl > ' 8.1.1.4' nl c Multiples
' 8.1.2.5' nl > ' 8.1.1.5' nl c Numbered collective
' 8.1.2.6' nl > ' 8.1.1.6' nl c Fraction
' 8.1.2.7' nl > ' 8.4.5.1' nl c Order, sequence
' 8.1.2.8' nl > ' 8.4.5.1.1' nl c Series
' 8.1.2.9' nl > ' 8.4.5.1.6' nl c Alternate
' 8.1.3' nl > ' 8.1.3.1' nl c Many
' 8.1.3.1' nl > ' 8.1.3.2' nl c Few
' 8.1.3.2' nl > ' 8.1.3.3' nl c Group of things
' 8.1.4.4' nl > ' 8.1.5.9' nl c Average
' 8.1.5.2' nl > ' 8.3.5.2.4' nl c Other
' 8.1.5.3' nl > ' 8.1.7.4' nl c Remainder
' 8.1.5.4' nl > ' 8.1.5.3' nl c Both
' 8.1.5.5' nl > ' 8.1.5.6' nl c Almost
' 8.1.5.6' nl > ' 8.1.5.7' nl c Only
' 8.1.5.7' nl > ' 8.1.5.8.1' nl c Approximately
' 8.1.7' nl > ' 8.1.3.1' nl c Much, little
' 8.1.8' nl > ' 9.3.1' nl c Degree
' 8.1.8.1' nl > ' 9.3.2' nl c Completely
' 8.2' nl > ' 8.2.8' nl c Measure
' 8.2.1' nl > ' 8.2.9' nl c Weight
' 8.2.1.1' nl > ' 8.2.9.1' nl c Heavy
' 8.2.1.2' nl > ' 8.2.9.2' nl c Light in weight
' 8.2.2.4' nl > ' 8.2.6.5' nl c Deep, shallow
' 8.2.2.5' nl > ' 8.2.4' nl c Wide
' 8.2.2.6' nl > ' 8.2.4.1' nl c Narrow
' 8.2.3' nl > ' 8.5.4' nl c Area
' 8.2.4' nl > ' 8.2.7' nl c Size
' 8.2.4.1' nl > ' 8.2' nl c Big
' 8.2.4.2' nl > ' 8.2.1' nl c Small
' 8.2.4.3' nl > ' 8.2' nl c Get larger
' 8.2.4.4' nl > ' 8.2.1' nl c Get smaller
' 8.2.4.5' nl > ' 8.2.3' nl c Fat, thick
' 8.2.4.6' nl > ' 8.2.3.1' nl c Thin
' 8.2.5' nl > ' 8.2.5.1' nl c Volume
' 8.2.5.1' nl > ' 8.1.8' nl c Full
' 8.2.5.2' nl > ' 8.1.8.1' nl c Empty
' 8.2.5.3' nl > ' 8.1.8' nl c Overflowing
' 8.2.6' nl > ' 8.2.7' nl c Fit, size
' 8.2.6.1' nl > ' 8.2.7.1' nl c Tight, loose
' 8.2.6.2' nl > ' 8.2.7.3' nl c Wedged in, stuck
' 8.3.1.8' nl > ' 8.3.1.8.1' nl c Symmetrical
' 8.3.2.3.2' nl > ' 8.3.2.3' nl c Sharpen
' 8.3.3.3.8' nl > ' 8.3.3.3' nl c Colorless
' 8.3.3.4' nl > ' 2.3.1.5' nl c Visible
' 8.3.3.5' nl > ' 2.3.1.5.1' nl c Appear
' 8.3.3.6' nl > ' 2.3.1.6' nl c Transparent
' 8.3.3.7' nl > ' 2.3.1.7' nl c Reflect
' 8.3.4.1' nl > ' 8.3.4' nl c Hot
' 8.3.4.2' nl > ' 8.3.4' nl c Warm
' 8.3.4.3' nl > ' 8.3.4.1' nl c Cold
' 8.3.4.4' nl > ' 8.3.4' nl c Change temperature
' 8.3.5' nl > ' 8.3.7.8' nl c Decay
' 8.3.5.1' nl > ' 8.3.7.8.1' nl c Eaten by rust, insects
' 8.3.5.2' nl > ' 7.9.3' nl c Ruined, spoiled
' 8.3.5.3' nl > ' 8.3.7.8.3' nl c Garbage
' 8.3.5.4' nl > ' 8.3.7.8.4' nl c Preserve
' 8.3.6' nl > ' 8.3.5' nl c Type, kind
' 8.3.6.1' nl > ' 8.3.5.1' nl c Nature, character
' 8.3.6.2' nl > ' 8.3.5.2' nl c Compare
' 8.3.6.2.1' nl > ' 8.3.5.2.1' nl c Same
' 8.3.6.2.2' nl > ' 8.3.5.2.2' nl c Like, similar
' 8.3.6.2.3' nl > ' 8.3.5.2.3' nl c Different
' 8.3.6.2.4' nl > ' 8.3.5.3' nl c Common
' 8.3.6.2.5' nl > ' 8.3.5.3.3' nl c Unique
' 8.3.6.2.6' nl > ' 8.3.5.3.1' nl c Usual
' 8.3.6.2.7' nl > ' 8.3.5.3.2' nl c Unusual
' 8.3.6.2.8' nl > ' 8.3.5.3.4' nl c Strange
' 8.3.6.3' nl > ' 8.3.5.4' nl c Pattern, model
' 8.3.6.4' nl > ' 8.3.5.5' nl c Imitate
' 8.3.7' nl > ' 8.3.6' nl c Made of, material
' 8.3.7.1' nl > ' 8.3.6.1' nl c Strong, brittle
' 8.3.7.2' nl > ' 8.3.6.2' nl c Hard, firm
' 8.3.7.3' nl > ' 8.3.6.3' nl c Stiff, flexible
' 8.3.7.4' nl > ' 8.3.6.4' nl c Dense
' 8.3.7.5' nl > ' 8.3.6.5' nl c Soft, flimsy
' 8.3.8' nl > ' 8.3.7' nl c Good
' 8.3.8.1' nl > ' 8.3.7.1' nl c Bad
' 8.3.8.2' nl > ' 8.3.7.2' nl c Better, surpass
' 8.3.8.2.1' nl > ' 8.3.7.2.1' nl c Worse, lesser
' 8.3.8.3' nl > ' 8.3.7.3' nl c Perfect
' 8.3.8.4' nl > ' 8.3.7.4' nl c Mediocre
' 8.3.8.5' nl > ' 8.3.7.5' nl c Important
' 8.3.8.5.1' nl > ' 8.3.7.5.1' nl c Basic
' 8.3.8.6' nl > ' 8.3.7.6' nl c Improve
' 8.3.8.7' nl > ' 8.3.7.7' nl c Right, proper
' 8.3.8.7.1' nl > ' 8.3.7.7.1' nl c Wrong, unsuitable
' 8.3.8.7.2' nl > ' 8.3.7.7.2' nl c Convenient
' 8.3.8.7.3' nl > ' 8.3.7.7.3' nl c Compatible
' 8.3.8.8' nl > ' 8.3.7.8.2' nl c Blemish
' 8.3.8.9' nl > ' 8.3.7.9' nl c Value
' 8.3.9' nl > ' 2.3.1.8' nl c Appearance
' 8.3.9.1' nl > ' 2.3.1.8.1' nl c Beautiful, ugly
' 8.3.9.2' nl > ' 8.3.8.2' nl c Glory
' 8.3.9.3' nl > ' 8.3.8' nl c Decorated
' 8.3.9.4' nl > ' 8.3.8.1' nl c Simple, plain
' 8.4.1.2.1' nl > ' 8.4.1.2.2' nl c Days relative to each other
' 8.4.2' nl > ' 8.4.1.2.3' nl c Time of the day
' 8.4.2.1' nl > ' 8.4.1.2.3' nl c Just before dawn
' 8.4.2.2' nl > ' 8.4.1.2.3' nl c Dawn
' 8.4.2.3' nl > ' 8.4.1.2.3' nl c Morning
' 8.4.2.4' nl > ' 8.4.1.2.3' nl c Noon
' 8.4.2.5' nl > ' 8.4.1.2.3' nl c Afternoon
' 8.4.2.6' nl > ' 8.4.1.2.3' nl c Sunset
' 8.4.2.7' nl > ' 8.4.1.2.3' nl c Evening
' 8.4.2.8' nl > ' 8.4.1.2.1' nl c Night
' 8.4.2.9' nl > ' 8.4.1.2.3' nl c Midnight
' 8.4.5.1.1' nl > ' 8.4.5.2' nl c Happen before
' 8.4.5.1.2' nl > ' 8.4.5.2.2' nl c Happen at same time
' 8.4.5.1.3' nl > ' 8.4.5.2.3' nl c During, while
' 8.4.5.1.4' nl > ' 8.4.5.2.1' nl c Happen after
' 8.4.5.2' nl > ' 8.4.5.1' nl c Temporal order
' 8.4.5.2.1' nl > ' 8.4.5.1.2' nl c Happen first
' 8.4.5.2.2' nl > ' 8.4.5.1.3' nl c Happen next
' 8.4.5.2.3' nl > ' 8.4.5.1.4' nl c Happen last
' 8.4.6.4.4' nl > ' 8.4.6.1.4' nl c Until
' 8.4.6.4.5' nl > ' 8.4.6.1.5' nl c From then on
' 8.4.6.4.6' nl > ' 8.4.6.4.4' nl c Immediate
' 8.4.6.5.1' nl > ' 8.4.6.5.3' nl c New
' 8.4.6.5.2' nl > ' 8.4.6.5.4' nl c Old
' 8.4.6.5.3' nl > ' 8.4.6.5.6' nl c Old fashioned
' 8.4.7' nl > ' 8.4.2' nl c Take time
' 8.4.7.1' nl > ' 8.4.7' nl c Continue, persevere
' 8.4.7.2' nl > ' 8.4.7.1' nl c Interrupt
' 8.4.7.3' nl > ' 8.4.7.2' nl c Start again
' 8.4.7.4' nl > ' 8.4.2.1' nl c A short time
' 8.4.7.5' nl > ' 8.4.2.2' nl c A long time
' 8.4.7.6' nl > ' 8.4.8.3' nl c Sudden
' 8.4.7.7' nl > ' 8.4.2.3' nl c Forever
' 8.4.7.8' nl > ' 8.4.2.4' nl c Temporary
' 8.4.7.9' nl > ' 8.4.7.3' nl c Interval
' 8.5.1.4' nl > ' 8.2.6.3' nl c High
' 8.5.1.4.1' nl > ' 8.2.6.4' nl c Low
' 8.5.1.5' nl > ' 8.5.1.4' nl c Inside
' 8.5.1.5.1' nl > ' 8.5.1.4.1' nl c Outside
' 8.5.1.6' nl > ' 8.2.6' nl c Distance
' 8.5.1.6.1' nl > ' 8.5.1.5' nl c Touching, contact
' 8.5.1.6.2' nl > ' 8.5.1.5.1' nl c Next to
' 8.5.1.6.3' nl > ' 8.2.6.2' nl c Near
' 8.5.1.6.4' nl > ' 8.2.6.1' nl c Far
' 8.5.1.7' nl > ' 8.5.1.6' nl c Across
' 8.5.1.8' nl > ' 8.6.5' nl c Center
' 8.5.1.9' nl > ' 8.5.1.7' nl c Indefinite location
' 8.5.4' nl > ' 8.5.4.1' nl c Vicinity
' 8.5.4.1' nl > ' 8.5.4.2' nl c Occupy an area
' 8.5.4.2' nl > ' 8.5.4.3' nl c Space, room
' 8.5.4.3' nl > ' 8.5.4.4' nl c Interval, space
' 9.1.1.1' nl > ' 9.1.1.2' nl c Become, change state
' 9.1.1.2' nl > ' 9.1.1.3' nl c Have, of
' 9.1.2.4' nl > ' 9.1.2.6' nl c Change something
' 9.3' nl > ' 9.1.2.7' nl c Propositions
' 9.3.1' nl > ' 9.1.2.7' nl c Event propositions
' 9.3.2' nl > ' 9.1.1.1' nl c Exist
' 9.3.3' nl > ' 9.6' nl c Connected with
' 9.3.3.1' nl > ' 8.5.6' nl c Contain
' 9.3.3.2' nl > ' 3.5.1.2.9' nl c Be about, depict
' 9.3.4' nl > ' 8.1.3' nl c Plurality
' 9.3.5' nl > ' 9.1.1.4' nl c Attribution
' 9.3.5.1' nl > ' 9.3.5' nl c Attribution of an attribute
' 9.3.5.2' nl > ' 9.3' nl c Very
' 9.3.5.3' nl > ' 9.3.1' nl c Degree on a scale
' 9.4.1.2.1' nl > ' 9.3.4' nl c Do intensely
' 9.4.2.3' nl > ' 6.1.2.1' nl c Try, attempt
' 9.4.2.4' nl > ' 8.1.7.3' nl c Requisite resources
' 9.4.3.1' nl > ' 9.4.4' nl c Epistemic moods
' 9.4.3.1.1' nl > ' 9.4.4.1' nl c Certainly, definitely
' 9.4.3.1.2' nl > ' 9.4.4.2' nl c Sure
' 9.4.3.1.3' nl > ' 9.4.4.3' nl c Probably
' 9.4.3.1.4' nl > ' 9.4.4.4' nl c Possible
' 9.4.3.1.5' nl > ' 9.4.4.5' nl c Uncertain
' 9.4.3.1.6' nl > ' 9.4.4.6' nl c Unsure
' 9.4.3.1.7' nl > ' 9.4.4.7' nl c Just, almost not
' 9.4.3.1.8' nl > ' 9.4.4.8' nl c Don't think so, doubt it
' 9.4.3.1.9' nl > ' 9.4.4.9' nl c Impossible
' 9.4.3.2' nl > ' 9.4.3.1' nl c Imperative
' 9.4.3.2.1' nl > ' 9.4.3.2' nl c Hortative
' 9.4.3.2.2' nl > ' 9.4.2.3' nl c Necessary
' 9.4.3.3' nl > ' 9.4.7' nl c Subordinating
' 9.4.3.4' nl > ' 9.6.2.8' nl c Conditional sentences
' 9.4.3.5' nl > ' 9.4.8' nl c Adverbial clauses
' 9.4.3.6' nl > ' 9.4.3.3' nl c Interrogative
' 9.4.3.7' nl > ' 9.4.4.6.3' nl c Seem
' 9.4.3.8' nl > ' 9.4.4.6.1' nl c Think so
' 9.4.3.9' nl > ' 9.4.4.6.2' nl c Maybe
' 9.4.4' nl > ' 9.4.5' nl c Evidentials
' 9.4.4.1' nl > ' 9.4.5.1' nl c Evaluator
' 9.4.5' nl > ' 9.4.6' nl c Affirmation
' 9.4.5.1' nl > ' 9.4.6.1' nl c Negation
' 9.4.5.2' nl > ' 9.4.6.2' nl c Markers expecting an affirmative answer
' 9.4.5.3' nl > ' 9.4.6.3' nl c Markers expecting a negative answer
' 9.5.3' nl > ' 9.6.2.5' nl c Causer
' 9.5.4' nl > ' 9.5.3' nl c Patient-related cases
' 9.5.4.1' nl > ' 9.5.3.1' nl c Beneficiary (of a patient)
' 9.5.4.2' nl > ' 9.5.3.2' nl c Recipient (of a patient)
' 9.5.4.3' nl > ' 9.5.3.3' nl c With (a patient)
' 9.6.1.9' nl > ' 8.5.1.2.2' nl c Mediation
' 9.6.2.5.1' nl > ' 9.6.2.5.2' nl c Without cause
' 9.6.2.7.2' nl > ' 9.6.2.7' nl c Negative purpose
