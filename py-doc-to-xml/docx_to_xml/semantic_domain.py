from __future__ import annotations

from semantic_domain import (
    AbbreviationType,
    AStrType,
    AUniType,
    CmDomainQType,
    CmSemanticDomainType,
    DescriptionType,
    ExampleSentencesType,
    ExampleWordsType,
    NameType,
    QuestionType,
    RunType,
    SubPossibilitiesType,
)


def display_a_uni(a_unis: list[AUniType], indent: int = 1) -> None:
    indent_str = "\t" * indent
    for uni in a_unis:
        print(f"{indent_str}{uni.ws}: {uni.valueOf_}")


def display_a_str(a_str: list[AStrType], indent: int = 1) -> None:
    indent_str = "\t" * indent
    for s in a_str:
        run: RunType = s.Run
        print(f"{indent_str}{s.ws}: {run.valueOf_}")


def display_questions(questions: list[CmDomainQType]) -> None:
    for domain_question in questions:
        print("\tDomain Question")
        question: QuestionType = domain_question.Question
        display_a_uni(question.AUni, indent=2)

        print("\tExample Words")
        examples: ExampleWordsType | None = domain_question.ExampleWords
        if examples is not None:
            display_a_uni(examples.AUni, indent=2)

        print("\tExample Sentences")
        sentences: ExampleSentencesType | None = domain_question.ExampleSentences
        if sentences is not None:
            display_a_str(sentences.AStr, indent=2)


def display_semantic_domain(semantic_domain: CmSemanticDomainType) -> None:
    print("Name")
    name: NameType = semantic_domain.Name
    display_a_uni(name.AUni)

    print("\nAbbreviation")
    abbreviation: AbbreviationType = semantic_domain.Abbreviation
    display_a_uni(abbreviation.AUni)

    print("\nDescription")
    description: DescriptionType = semantic_domain.Description
    display_a_str(description.AStr)

    print("\nQuestions")
    display_questions(semantic_domain.Questions.CmDomainQ)

    print("\nSubPossibilities")
    possibilities: SubPossibilitiesType | None = semantic_domain.SubPossibilities
    if possibilities is not None:
        for domain in possibilities.CmSemanticDomain:  # type: CmSemanticDomainType
            display_semantic_domain(domain)